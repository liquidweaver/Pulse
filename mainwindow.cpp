#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>
#include <QRegExp>
#include <QMessageBox>
#include <stdexcept>
#include <QPair>
#include <QList>
#include <QPushButton>
#include <QStandardItemModel>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QFileDialog>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QMap>
#include <QString>
#include <QTimer>
#include "soci-3.1.0/core/soci.h"
#include "soci-3.1.0/core/error.h"
#include "settings.h"
#include "service.h"
#include <QDateTime>
#include "global_defines.h"
#include "metrosettings.h"

#define MULTILINE(...) #__VA_ARGS__

typedef QPair<QString, QString> QStringPair;
MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   resize = false;
   ui->setupUi(this);
   QStandardItemModel* model = new QStandardItemModel();
   ui->treeView->setModel( model  );
   int settings_version;
   { MetroSettings settings;
      settings_version = settings.value( "main/pulse_settings_serial" ).toInt();
   }
   if ( PULSE_SETTINGS_SERIAL != settings_version ) {
      int ret = QMessageBox::warning(this, "Incompatible settings detected",
                                     tr("Your settings are no longer compatible with "
                                        "this version of Pulse. OK to load defaults?"),
                                     QMessageBox::Abort | QMessageBox::Ok, QMessageBox::Abort );
      if ( ret != QMessageBox::Ok ) {
         throw std::runtime_error( "Incompatible settings" );
      }
      else {
         LoadDefaultSettings();
      }
   }
   try{
      m_show_close_warning = true;

      //Set service handlers
      QMap<QString, Service> services = LoadServices();
      QMap<QString, Service>::const_iterator it;
      for (it = services.begin(); it != services.end(); it++ ) {
         QDesktopServices::setUrlHandler( it.key(), this, "service_url_handler");
      }

      QAction* quitAction = new QAction(tr("&Quit"), this);
      connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

      QMenu *trayMenu = new QMenu(this);
      trayMenu->addAction(tr("Show"), this, SLOT(show()));
      trayMenu->addAction(tr("Hide"), this, SLOT(hide()));
      trayMenu->addSeparator();
      trayMenu->addAction(quitAction);

      m_tray_icon = new QSystemTrayIcon( QIcon(":/ico/PNG/pulse.png"), this );
      m_tray_icon->setContextMenu( trayMenu );
      m_tray_icon->show();
      connect( m_tray_icon, SIGNAL(messageClicked()), this, SLOT(showNormal()) );
      connect( m_tray_icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(TrayClicked(QSystemTrayIcon::ActivationReason)) );
      connect( &m_ticket_timer, SIGNAL(timeout()), this, SLOT(LoadTickets()));
      connect( &m_zone_timer, SIGNAL(timeout()), this, SLOT(LoadZones()));
      connect( &m_techs_timer, SIGNAL(timeout()), this, SLOT(LoadTechs()));
      m_ticket_timer.start( TICKET_REFRESH_INTERVAL );
      m_zone_timer.start( ZONE_REFRESH_INTERVAL );
      m_techs_timer.start( TECH_REFRESH_INTERVAL );
      //QSplitterHandle *handle = ui->splitter->handle(1);
      //QVBoxLayout *layout = new QVBoxLayout(handle);
      //layout->setSpacing(0);
      //layout->setMargin(0);

      //QFrame *line = new QFrame(handle);
      //line->setFrameShape(QFrame::Panel);
      //line->setFrameShadow(QFrame::Raised);
      //layout->addWidget(line);


      ui->table_techs->horizontalHeader()->setResizeMode(QHeaderView::Interactive);
      ui->table_techs->horizontalHeader()->setStretchLastSection(true);
      ui->table_techs->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
      ui->table_tickets->horizontalHeader()->setResizeMode(QHeaderView::Interactive);
      ui->table_tickets->horizontalHeader()->setStretchLastSection(true);
      ui->table_tickets->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
      LoadZones();
      LoadTickets();
      LoadTechs();
   }
   catch ( std::runtime_error& except ) {
      qDebug() << except.what();
   }
}

MainWindow::~MainWindow() {
   delete ui;
}

void MainWindow::AddRecord( NameRecord& rec ) {
   QStringList doms = rec.Name().split( QChar('.') );
   QListIterator<QString> it(doms);
   it.toBack();
   QStandardItem* leaf = static_cast<QStandardItemModel*>(ui->treeView->model())->invisibleRootItem();
   while( it.hasPrevious() ) {
      QString dom = it.previous();
      bool found = false;
      for (int i = 0; i < leaf->rowCount(); i++ ) {
         if ( leaf->child(i, 0)->data( Qt::DisplayRole ) == dom ) {
            leaf = leaf->child(i, 0);
            found = true;
            break;
         }
      }
      if (!found) {
         QList<QStandardItem*> row;
         QStandardItem* new_child = new QStandardItem;
         if (it.hasPrevious() )
            new_child->setData(dom, Qt::DisplayRole);
         else
            new_child->setData(rec.Name(), Qt::DisplayRole );
         row << new_child << new QStandardItem();
         leaf->appendRow(row);
         leaf = new_child;
      }
   }

}

void MainWindow::ZoneTransfer( const QString& zone_name, QList<NameRecord>& records  ) {
   QString SOA = GrabZoneSOA( zone_name );
#ifdef Q_OS_WIN32
   QString axfr_result = RunExternal( tr("nslookup"), tr("server %0\nls -d %1\nquit\n").arg(SOA).arg(zone_name));
   QRegExp rr_rx("([\\._a-zA-Z\\d-]{1,63})\\s+((TXT)|(A))\\s+\"?([\\._a-zA-Z\\d -]{1,63})\"?");
#else
   QProcess process;
   QStringList args;
   args << "axfr" << zone_name << tr("@%0").arg(SOA);
   process.start( tr("dig"), args );
   if(!process.waitForFinished())
      throw std::runtime_error( "GrabZoneSOA :dig never finished" );

   QString axfr_result  = process.readAll();
   QRegExp rr_rx("([\\._a-zA-Z\\d-]{1,63})\\s+\\d+\\s+IN\\s+((TXT)|(A))\\s+\"?([\\._a-zA-Z\\d -]{1,63})\"?");
#endif

   int pos = rr_rx.indexIn(axfr_result, 0);
   while( pos != -1 ) {
      QString name = rr_rx.cap(1).trimmed();
      if (name.endsWith('.'))
         name.chop(1);
      else
         name += '.' + zone_name;
      NameRecord rec(name, rr_rx.cap(2).trimmed(), rr_rx.cap(5).trimmed());
      records.append( rec );
      pos = rr_rx.indexIn(axfr_result, pos + rr_rx.matchedLength() );
   }

}

QString MainWindow::GrabZoneSOA( const QString& zone_name) {
   QString result = RunExternal( tr("nslookup"), tr("set type=SOA\n%0\nquit\n").arg(zone_name));

   QRegExp pri_ns("((primary name server)|(origin))\\s*=\\s*([^\\s\\r\\n]+)");
   int pos = pri_ns.indexIn( result );
   if (pos > -1) {
      return pri_ns.cap(4);
   }
   else
      throw std::runtime_error( "SOA not found for zone." );

}

QString MainWindow::RunExternal( const QString& cmd, const QString& input) {
   QProcess process;
   process.start(cmd);
   if (!process.waitForStarted())
      throw std::runtime_error( tr("RunExternal:Cannot execute %0").arg(cmd).toStdString() );

   process.write(input.toAscii());
   process.closeWriteChannel();
   if(!process.waitForFinished())
      throw std::runtime_error( tr("RunExternal:%0 never finished").arg(cmd).toStdString() );

   QString result = process.readAll();

   return result;

}

void MainWindow::LoadZones() {
   try {
      QList<NameRecord> records;
      MetroSettings settings;
      QMap<QString, QStringList> services;
      //TODO: Load zone from settings
      QString zone = settings.value(SETTING_ZONE).toString();
      if ( zone.isNull() )
         throw std::runtime_error( "DNS Zone not set." );
      QStandardItemModel* model = static_cast<QStandardItemModel*>( ui->treeView->model() );
      model->clear();
      QStringList header;
      header << "Host" << "Services";
      model->setHorizontalHeaderLabels( header );
      ui->treeView->header()->setStretchLastSection(false);
      ui->treeView->header()->setResizeMode(0, QHeaderView::Stretch);
      ui->treeView->header()->setResizeMode(1, QHeaderView::Interactive);
      int size = settings.beginReadArray( "zones" );
      m_zone_timer.setInterval( ZONE_REFRESH_INTERVAL );
      if ( size == 0 )
         throw std::runtime_error( "No zones defined; define them under Settings->Zones." );
      for ( int i=0; i<size; i++ ) {
         settings.setArrayIndex( i );
         try {
            ZoneTransfer( settings.value("name").toString(), records );
         } catch ( std::exception &e ) {
            ui->statusBar->showMessage( tr("Could not load zone %0: %1")
                                        .arg(settings.value("name").toString())
                                        .arg(e.what() ),
                                        STATUSBAR_ERROR_LINGER );
            m_zone_timer.setInterval( ERROR_REFRESH_INTERVAL );
         }
      }
      settings.endArray();
      if ( records.count() < 1 )
         throw std::runtime_error( "No DNS records found; check network connection." );
      foreach( NameRecord rec, records ) {
         if (rec.Type() == "A")
            AddRecord( rec ); //Only process host records
         else if (rec.Type() == "TXT" )
            services[ rec.Name()] = rec.Data().split(' ');
      }

      QMapIterator<QString, QStringList> i(services);
      while (i.hasNext() ) {
         i.next();
         QList<QStandardItem*> results = model->findItems( i.key(), Qt::MatchExactly | Qt::MatchRecursive );
         if ( results.count() > 0 ) {
            QString service_links;
            QWidget *link_container = new QWidget();
            QHBoxLayout *layout = new QHBoxLayout;
            if ( ! i.value().contains("ping", Qt::CaseInsensitive ) ) {
               QLabel *new_link = new QLabel( tr("<a href=\"%0://%1\">%0</a>").arg( tr("ping") ).arg( tr("ping") ) );
               layout->addWidget(new_link);
               connect( new_link, SIGNAL(linkActivated(QString)), this, SLOT(service_link_handler(QString)));
            }
            foreach( QString service, i.value()) {
               QLabel *new_link = new QLabel( tr("<a href=\"%0://%1\">%0</a>").arg(service.toLower()).arg(i.key()) );
               layout->addWidget(new_link);
               connect( new_link, SIGNAL(linkActivated(QString)), this, SLOT(service_link_handler(QString)));
            }
            const QStandardItem * this_cell = results[0];
            QStandardItem* cell = this_cell->parent()->child( this_cell->index().row(),
                                                              this_cell->index().column() + 1 );
            QModelIndex over_one = cell->index();
            link_container->setLayout(layout);
            //setLayout(layout);

            ui->treeView->setIndexWidget( over_one, link_container );
         }
      }
      ui->treeView->expandToDepth(0);
      ui->treeView->header()->moveSection(1, 0);
      ui->lbl_zone_error->hide();
      ui->treeView->show();
      m_zone_timer.setInterval( ZONE_REFRESH_INTERVAL );
   }
   catch ( std::exception& e ) {
      ui->treeView->hide();
      ui->lbl_zone_error->setText( tr( "An error occured while fetching network information. Retrying in %0 seconds. Error information:<hr><div style=\"font-weight: bold; margin-left: 16px;\">%1</div>" ).arg(ERROR_REFRESH_INTERVAL / 1000).arg( e.what() ) );
      ui->lbl_zone_error->show();
      m_zone_timer.setInterval( ERROR_REFRESH_INTERVAL );
   }
}

void MainWindow::LoadTickets() {
   using soci::row;
   using soci::rowset;
   using soci::session;
   using std::string;
   try {
      MetroSettings settings;
      QString merp_host = settings.value( SETTING_MERP_HOST ).toString();
      QString db_name = settings.value( SETTING_DB_NAME ).toString();
      QString db_user = settings.value( SETTING_DB_USER ).toString();
      QString db_pass = settings.value( SETTING_DB_PASS ).toString();
      if ( merp_host.isNull() )
         throw QString("MERP host not set.");
      else if ( db_name.isNull() )
         throw QString( "Database name not set.");
      else if ( db_user.isNull() )
         throw QString( "Database user not set.");
      else if ( db_pass.isNull() ) {
         throw QString( "Database secret not set.");
      }
      session sql( tr("postgresql://dbname=%0 host=%1 user=%2 password=%3").arg(db_name).arg(merp_host).arg(db_user).arg(db_pass).toStdString() );
      //note: the timezone stuff is... tricky, and is highly dependent on the pulse role's preferred time format...  egh.
      const char *query = MULTILINE(
select pt.weight,cmh.ticket_no, pt.name, ruo.name, rp.name, foo.name, foo.time_spent, case when bar.escalated then bar.escalated else false end as escalated
from crm_metro_helpdesk as cmh 
inner join project_task as pt on pt.helpdesk_id = cmh.id 
inner join res_users as ruo on ruo.id = pt.user_id 
inner join res_partner as rp on rp.id = pt.partner_id 
left join res_users as ruw on ruw.id = pt.worker_user_id 
left join (select task_id,
           string_agg(ru.name, E', \r\n') as name,
           (timestamp without time zone '1970-01-01' at time zone 'utc') + sum(now() - ptwr.create_date at time zone 'utc') as time_spent
       from project_task_worker_ref as ptwr inner join res_users as ru on ru.id = ptwr.user_id GROUP BY task_id) as foo on foo.task_id = pt.id
left join (select pt.id, true as escalated from project_task as pt 
    inner join project_task_tag_rel as pttr on pttr.task_id = pt.id 
    where pttr.tag_id in (select id from project_task_tag where key = 'escalation') and weight > 0) as bar on bar.id = pt.id
where pt.state = 'open' AND
pt.weight > 
    (select value_integer from ir_property where name = 'property_helpdesk_weight_hot_threshold') 
order by pt.weight desc;
);
      
      rowset<row> rs = (sql.prepare << query);
      // iteration through the resultset:
      ui->table_tickets->clearContents();
      ui->table_tickets->setRowCount(0);
      int row_id=0;
      for (rowset<row>::const_iterator it = rs.begin(); it != rs.end(); ++it)
      {
         row const& row = *it;
         int priority;
         string tech, description, ticket_id, customer_name, worker_name;
         std::tm worker_start;
	 int escalated;

         // dynamic data extraction from each row:
         time_t default_time_t = 0;
         std::tm* default_tm = localtime( &default_time_t );
         priority = row.get<int>(0);
         ticket_id = row.get<string>(1);
         description = row.get<string>(2);
         tech = row.get<string>(3);
         customer_name = row.get<string>(4);
         worker_name = row.get<string>(5, string("") );
         worker_start = row.get<std::tm>(6, *default_tm );
         escalated = row.get<int>(7);
         //qint64 mins = QDateTimeFromTM( worker_start ).msecsTo( QDateTime::currentDateTime() ) / 1000 / 60;
         qint64 mins = QDateTimeFromTM( worker_start ).toMSecsSinceEpoch() / 1000 / 60;
         qint64 hours = mins / 60;
         qint64 minutes = mins % 60;
         QString minutes_formatted = minutes >= 10 ? QString("%0").arg(minutes) : QString("0%0").arg(minutes);
         QString duration;
         if ( !worker_name.empty() ){
            duration = (hours > 0)
                       ? tr("%0:%1").arg(hours).arg(minutes_formatted)
                       : tr("%0 minute(s)").arg(mins);
         }

         ui->table_tickets->insertRow(row_id);
         ui->table_tickets->setItem(row_id, 0, new QTableWidgetItem( QString("%0").arg(priority) ) );
         ui->table_tickets->setItem(row_id, 1, new QTableWidgetItem( QString(ticket_id.c_str())));
         ui->table_tickets->setItem(row_id, 2, new QTableWidgetItem( QString(tech.c_str())));
         ui->table_tickets->setItem(row_id, 3, new QTableWidgetItem( QString(worker_name.c_str())));
         ui->table_tickets->setItem(row_id, 4, new QTableWidgetItem( duration ) );
         ui->table_tickets->setItem(row_id, 5, new QTableWidgetItem( QString(customer_name.c_str())));
         ui->table_tickets->setItem(row_id, 6, new QTableWidgetItem( QString(description.c_str())));

         if(escalated){
             for(int i=0; i <=6; i++) {
                ui->table_tickets->item(row_id,i)->setBackgroundColor(QColor::fromRgb(255, 255, 153));  //Qt::yellow
             }
         }
         row_id++;

      }
      ui->lbl_tickets_error->hide();
      if(this->resize){
        ui->table_tickets->resizeColumnsToContents();
        ui->table_tickets->resizeRowsToContents();
      }
      ui->table_tickets->show();
      m_ticket_timer.setInterval( TICKET_REFRESH_INTERVAL );
      if ( row_id > 0 )
         m_tray_icon->showMessage( "Pulse - Hot Tickets", tr("Pulse has discovered %0 active hot tickets!").arg( row_id ), QSystemTrayIcon::Warning );
   }
   catch ( soci::soci_error& error) {
      ui->table_tickets->hide();
      ui->lbl_tickets_error->setText( tr( "An error occured while fetching ticket information. Retrying in %0 seconds. Error information:<hr><div style=\"font-weight: bold; margin-left: 16px;\">%1</div>" ).arg(ERROR_REFRESH_INTERVAL / 1000).arg( error.what() ) );
      ui->lbl_tickets_error->show();
      m_ticket_timer.setInterval( ERROR_REFRESH_INTERVAL );
   }
   catch ( QString& error ) {
      ui->table_tickets->hide();
      ui->lbl_tickets_error->setText( tr( "An error occured while fetching ticket information. Retrying in %0 seconds. Error information:<hr><div style=\"font-weight: bold; margin-left: 16px;\">%1</div>" ).arg(ERROR_REFRESH_INTERVAL / 1000).arg( error ) );
      ui->lbl_tickets_error->show();
      m_ticket_timer.setInterval( ERROR_REFRESH_INTERVAL );
   }
}

void MainWindow::LoadTechs() {
   using soci::row;
   using soci::rowset;
   using soci::session;
   using std::string;
   try {
      MetroSettings settings;
      QString merp_host = settings.value( SETTING_MERP_HOST ).toString();
      QString db_name = settings.value( SETTING_DB_NAME ).toString();
      QString db_user = settings.value( SETTING_DB_USER ).toString();
      QString db_pass = settings.value( SETTING_DB_PASS ).toString();
      if ( merp_host.isNull() )
         throw QString("MERP host not set.");
      else if ( db_name.isNull() )
         throw QString( "Database name not set.");
      else if ( db_user.isNull() )
         throw QString( "Database user not set.");
      else if ( db_pass.isNull() ) {
         throw QString( "Database secret not set.");
      }
      session sql( tr("postgresql://dbname=%0 host=%1 user=%2 password=%3").arg(db_name).arg(merp_host).arg(db_user).arg(db_pass).toStdString() );
      
      const char *query = MULTILINE(
select ru.name, t.name, rp.name, t.weight, t.wstart, t.escalated
  from public.res_users as ru 
  inner join res_groups_users_rel as rgur on rgur.uid = ru.id 
  inner join res_groups as rg on 
      rg.id = rgur.gid AND rg.name = 'Pulse'
  inner join 
      (select ptwr.user_id, pt.id, name, weight, partner_id, ptwr.create_date at time zone 'UTC' as wstart, 
	case when bar.escalated then bar.escalated else false end as escalated 
      from project_task_worker_ref as ptwr
      inner join project_task as pt on pt.id = ptwr.task_id
      left join (select pt.id, true as escalated from project_task as pt 
	inner join project_task_tag_rel as pttr on pttr.task_id = pt.id 
	where pttr.tag_id in (select id from project_task_tag where key = 'escalation') and weight > 0) as bar on bar.id = pt.id
      WHERE pt.state='open' ) as t 
      on t.user_id = ru.id 
  inner join res_partner rp on rp.id = t.partner_id 
  order by t.wstart ASC
);      
      
      rowset<row> rs = (sql.prepare << query);
      // iteration through the resultset:
      ui->table_techs->clearContents();
      ui->table_techs->setRowCount(0);
      int row_id=0;
      for (rowset<row>::const_iterator it = rs.begin(); it != rs.end(); ++it) {
         row const& row = *it;
         int priority;
         string tech, description, customer_name;
         std::tm worker_start;
	 int escalated;

         // dynamic data extraction from each row:
         time_t default_time_t = 0;
         std::tm* default_tm = localtime( &default_time_t );

         tech = row.get<string>(0);
         description = row.get<string>(1,"");
         customer_name = row.get<string>(2);
         priority = row.get<int>(3);
         worker_start = row.get<std::tm>(4, *default_tm );
	 escalated = row.get<int>(5);

         qint64 mins = QDateTimeFromTM( worker_start ).msecsTo( QDateTime::currentDateTime() ) / 1000 / 60;
         qint64 hours = mins / 60;
         qint64 minutes = mins % 60;
	 QString minutes_formatted = minutes >= 10 ? QString("%0").arg(minutes) : QString("0%0").arg(minutes);
         QString duration;
         duration = (hours > 0)
                    ? tr("%0:%1").arg(hours).arg(minutes_formatted)
                    : tr("%0 minute(s)").arg(mins);

         ui->table_techs->insertRow(row_id);
         ui->table_techs->setItem(row_id, 0, new QTableWidgetItem( QString(tech.c_str())));
         ui->table_techs->setItem(row_id, 1, new QTableWidgetItem( QString("%0").arg(priority) ) );
         ui->table_techs->setItem(row_id, 2, new QTableWidgetItem( duration ) );
         ui->table_techs->setItem(row_id, 3, new QTableWidgetItem( QString(customer_name.c_str())));
         ui->table_techs->setItem(row_id, 4, new QTableWidgetItem( QString(description.c_str())));

         if(escalated){
             for(int i=0; i <=4; i++) {
                ui->table_techs->item(row_id,i)->setBackgroundColor(QColor::fromRgb(255, 255, 153));  //Qt::yellow
             }
         }
         
         row_id++;
      }
      ui->lbl_techs_error->hide();
      if(this->resize){
        ui->table_techs->resizeColumnsToContents();
        ui->table_techs->resizeRowsToContents();
      }
      ui->table_techs->show();
      m_techs_timer.setInterval( TECH_REFRESH_INTERVAL );
   }
   catch ( soci::soci_error& error) {
      ui->table_techs->hide();
      ui->lbl_techs_error->setText( tr( "An error occured while fetching tech information. Retrying in %0 seconds. Error information:<hr><div style=\"font-weight: bold; margin-left: 16px;\">%1</div>" ).arg(ERROR_REFRESH_INTERVAL / 1000).arg( error.what() ) );
      ui->lbl_techs_error->show();
      m_techs_timer.setInterval( ERROR_REFRESH_INTERVAL );
   }
   catch ( QString& error ) {
      ui->table_techs->hide();
      ui->lbl_techs_error->setText( tr( "An error occured while fetching tech information. Retrying in %0 seconds. Error information:<hr><div style=\"font-weight: bold; margin-left: 16px;\">%1</div>" ).arg(ERROR_REFRESH_INTERVAL / 1000).arg( error ) );
      ui->lbl_techs_error->show();
      m_techs_timer.setInterval( ERROR_REFRESH_INTERVAL );
   }
}

void MainWindow::SetServiceLocation( const QString& service_name ) {
   QString fileName = QFileDialog::getOpenFileName(this, tr("Where is the program to handle the %0 protocol?").arg(service_name),
                                                   QDesktopServices::storageLocation( QDesktopServices::ApplicationsLocation ),
                                                #ifdef Q_OS_WIN32
                                                   tr("Programs (*.exe)"));
#else
                                                   tr("Programs (*)"));
#endif
   //TODO: Open dialog?
   if (!fileName.isNull() ) {
      QMap<QString, Service> services = LoadServices();
      services[service_name].name = service_name;
      services[service_name].program_path = fileName;
      services[service_name].argument_string = "#";
      SaveServices( services );
   }
}

void MainWindow::service_link_handler(const QString &link) {
   service_url_handler( QUrl(link) );
}

void MainWindow::service_url_handler( const QUrl& url ) {
   QMap<QString, Service> services = LoadServices();
   QMap<QString, Service>::const_iterator it_svc = services.find( url.scheme() );
   try {
      if ( it_svc != services.end() ) {
         const Service& svc = it_svc.value();
         QString arguments( svc.argument_string );
         if ( arguments.contains('#') )
            arguments = arguments.replace( '#', url.host() );
         else
            arguments = url.host();
#ifdef Q_OS_WIN
         QStringList arglist;
         arglist << arguments.split(' ');

         bool started = QProcess::startDetached( svc.program_path, arglist );
#else
         bool started = QProcess::startDetached( QString( "%0 %1").arg( svc.program_path ).arg( arguments ) );
#endif
         if (!started)
            throw QString("Could not start %0.").arg(QDir::toNativeSeparators( svc.program_path ) );
      }
      else
         throw QString("I don't know how to handle the service \"%0.\"").arg(url.scheme());
   }
   catch ( QString error ) {
      if ( QMessageBox::Yes == QMessageBox::critical( this, tr("Problem" ),
                                                      tr("%0 Would you like to show me where to find the right program?" ).arg(error),
                                                      QMessageBox::Yes | QMessageBox::No  ) ) {
         SetServiceLocation( url.scheme() );
      }
   }

}

void MainWindow::closeEvent(QCloseEvent *event)
{
   if (m_tray_icon->isVisible()) {
      if (m_show_close_warning ) {
         m_tray_icon->showMessage( tr("Pulse"),
                                   tr("Pulse will keep running in the "
                                      "system tray. To terminate the program, "
                                      "choose \"Quit\" in the context menu "
                                      "of the pulse sytem tray icon or from the "
                                      "main window menu."));
         m_show_close_warning = false;
      }
      hide();
      event->ignore();
   }
}


void MainWindow::SaveServices( const QMap<QString, Service>& service_map ) {
   MetroSettings settings;
   settings.beginWriteArray("services");
   int i = 0;
   for ( QMap<QString, Service>::const_iterator svc_it = service_map.begin();
         svc_it != service_map.end(); svc_it++ ) {
      const Service& svc = svc_it.value();
      settings.setArrayIndex(i);
      settings.setValue("name", svc.name );
      settings.setValue("program_path", svc.program_path );
      settings.setValue("argument_string", svc.argument_string );
      i++;
   }

   settings.endArray();
}

QMap<QString, Service> MainWindow::LoadServices() {
   MetroSettings settings;
   QMap<QString, Service> services;
   int size = settings.beginReadArray( "services" );
   for (int i=0; i < size; i++ ) {
      settings.setArrayIndex(i);
      Service svc;
      svc.name = settings.value("name").toString();
      svc.program_path = settings.value("program_path").toString();
      svc.argument_string = settings.value("argument_string").toString();
      services[svc.name] = svc;
   }
   settings.endArray();

   return services;
}

void MainWindow::Quit() {
   QCoreApplication::quit();
}

void MainWindow::ShowSettings() {
   SettingsDialog settings_window;
   if ( QDialog::Accepted == settings_window.exec() ) {
      settings_window.SaveSettings();
      LoadZones(); LoadTickets();
   }
}

void MainWindow::ShowAbout() {
   QMessageBox::about( this, "About Pulse", "Metropark Pulse\nVersion " PULSE_VERSION );
}

void MainWindow::ShowTheatre(bool show ) {
   if ( show ) {
      ui->dock_network_browser->hide();
      this->showFullScreen();
      this->setStyleSheet( "font-size:16pt;");
   }
   else {
      ui->dock_network_browser->show();
      this->showNormal();
      this->setStyleSheet( "" );
   }

}

void MainWindow::AutoResize(bool resize) {
    this->resize = resize;
    if (resize) {   //do initial resize to kick things off
        ui->table_techs->resizeColumnsToContents();
        ui->table_techs->resizeRowsToContents();
        ui->table_tickets->resizeColumnsToContents();
        ui->table_tickets->resizeRowsToContents();
    }
}

void MainWindow::TrayClicked(QSystemTrayIcon::ActivationReason reason) {
   if ( reason == QSystemTrayIcon::DoubleClick ) {
      showNormal();
   }
}

void MainWindow::NetworkVisibilityChanged(bool visible) {
   ui->actionNetwork_Browser->setChecked(visible);
}

void MainWindow::TechVisibilityChanged(bool visible) {
   ui->actionTechs->setChecked(visible);
}

void MainWindow::showNormal() {
   QMainWindow::showNormal();
   this->activateWindow();
   this->raise();
}

QDateTime MainWindow::QDateTimeFromTM(std::tm& t ) {
   QDateTime qdt;

   qdt.setTime_t( mktime( &t ) );

   return qdt;
}

void MainWindow::LoadDefaultSettings() {
   MetroSettings settings;
   settings.clear();
   settings.setValue( SETTING_SERIAL, PULSE_SETTINGS_SERIAL );
   settings.setValue( SETTING_ZONE, "customer.mp" );
   settings.setValue( SETTING_MERP_HOST, "erp.mp" );
   settings.setValue( SETTING_DB_NAME, "metropark" );
   settings.setValue( SETTING_DB_USER, "pulse" );
   settings.setValue( SETTING_DB_PASS, "tigerpaw10" );

   { const char* default_zones[] = DEFAULT_ZONES;
      settings.beginWriteArray("zones");
      for (int i=0; NULL != default_zones[i]; i++ ) {
         settings.setArrayIndex(i);
         settings.setValue( "name", default_zones[i]);
      }
      settings.endArray();
   }
#ifdef Q_OS_WIN32
   { const char* default_services[] = DEFAULT_SERVICES_WINDOWS;
      settings.beginWriteArray("services");
      for( int i=0, j=0; default_services[i] != NULL; i+=3, j++ ) {
         settings.setArrayIndex(j);
         settings.setValue( "name", default_services[i]);
         settings.setValue( "argument_string", default_services[i+1]);
         settings.setValue( "program_path", default_services[i+2]);
      }
      settings.endArray();
   }
#else
   { const char* default_services[] = DEFAULT_SERVICES_LINUX;
      settings.beginWriteArray("services");
      for( int i=0, j=0; default_services[i] != NULL; i+=3, j++ ) {
         settings.setArrayIndex(j);
         settings.setValue( "name", default_services[i]);
         settings.setValue( "argument_string", default_services[i+1]);
         settings.setValue( "program_path", default_services[i+2]);
      }
      settings.endArray();
   }
#endif
}
