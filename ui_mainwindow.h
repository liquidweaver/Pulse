/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Aug 16 17:59:05 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSettings;
    QAction *action_Quit;
    QAction *actionReload_Network;
    QAction *actionFont_Size;
    QAction *actionAbout;
    QAction *actionNetwork_Browser;
    QAction *actionTechs;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *table_tickets;
    QLabel *lbl_tickets_error;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuWindows;
    QDockWidget *dock_network_browser;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QTreeView *treeView;
    QLabel *lbl_zone_error;
    QDockWidget *dock_techs;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *table_techs;
    QLabel *lbl_techs_error;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1044, 602);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/PNG/pulse.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QSplitter::handle {\n"
"qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147))\n"
"\n"
"     }"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/PNG/48/Gnome-Preferences-System-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon1);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ico/PNG/32/Gnome-System-Shutdown-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Quit->setIcon(icon2);
        actionReload_Network = new QAction(MainWindow);
        actionReload_Network->setObjectName(QString::fromUtf8("actionReload_Network"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ico/PNG/64/Gnome-Preferences-Desktop-Remote-Desktop-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReload_Network->setIcon(icon3);
        actionFont_Size = new QAction(MainWindow);
        actionFont_Size->setObjectName(QString::fromUtf8("actionFont_Size"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout->setIcon(icon);
        actionNetwork_Browser = new QAction(MainWindow);
        actionNetwork_Browser->setObjectName(QString::fromUtf8("actionNetwork_Browser"));
        actionNetwork_Browser->setCheckable(true);
        actionNetwork_Browser->setChecked(true);
        actionNetwork_Browser->setIcon(icon3);
        actionTechs = new QAction(MainWindow);
        actionTechs->setObjectName(QString::fromUtf8("actionTechs"));
        actionTechs->setCheckable(true);
        actionTechs->setChecked(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ico/PNG/64/Gnome-System-Users-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTechs->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox_2->setFont(font);
        groupBox_2->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        table_tickets = new QTableWidget(groupBox_2);
        if (table_tickets->columnCount() < 7)
            table_tickets->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_tickets->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_tickets->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_tickets->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_tickets->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_tickets->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_tickets->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_tickets->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        table_tickets->setObjectName(QString::fromUtf8("table_tickets"));
        table_tickets->setStyleSheet(QString::fromUtf8("QTableWidget {background-image: url(:/ico/PNG/64/Gnome-Emblem-Documents-64.png);\n"
"background-repeat:no-repeat;\n"
"background-attachment:fixed;\n"
"background-position:bottom right; \n"
"text-align:left;}"));
        table_tickets->setFrameShape(QFrame::Box);
        table_tickets->setLineWidth(0);
        table_tickets->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_tickets->setShowGrid(false);
        table_tickets->setCornerButtonEnabled(false);
        table_tickets->horizontalHeader()->setStretchLastSection(true);
        table_tickets->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(table_tickets);

        lbl_tickets_error = new QLabel(groupBox_2);
        lbl_tickets_error->setObjectName(QString::fromUtf8("lbl_tickets_error"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        lbl_tickets_error->setFont(font1);
        lbl_tickets_error->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(lbl_tickets_error);


        verticalLayout->addWidget(groupBox_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1044, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuWindows = new QMenu(menuBar);
        menuWindows->setObjectName(QString::fromUtf8("menuWindows"));
        MainWindow->setMenuBar(menuBar);
        dock_network_browser = new QDockWidget(MainWindow);
        dock_network_browser->setObjectName(QString::fromUtf8("dock_network_browser"));
        dock_network_browser->setFeatures(QDockWidget::DockWidgetFeatureMask);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(dockWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        treeView = new QTreeView(groupBox);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setFrameShape(QFrame::Box);
        treeView->setFrameShadow(QFrame::Sunken);
        treeView->setAlternatingRowColors(true);
        treeView->setSelectionMode(QAbstractItemView::NoSelection);
        treeView->setSelectionBehavior(QAbstractItemView::SelectItems);
        treeView->setIndentation(10);
        treeView->setAnimated(true);
        treeView->setAllColumnsShowFocus(true);

        verticalLayout_3->addWidget(treeView);

        lbl_zone_error = new QLabel(groupBox);
        lbl_zone_error->setObjectName(QString::fromUtf8("lbl_zone_error"));
        lbl_zone_error->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_3->addWidget(lbl_zone_error);


        verticalLayout_4->addWidget(groupBox);

        dock_network_browser->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_network_browser);
        dock_techs = new QDockWidget(MainWindow);
        dock_techs->setObjectName(QString::fromUtf8("dock_techs"));
        dock_techs->setMinimumSize(QSize(400, 188));
        dock_techs->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_3 = new QGroupBox(dockWidgetContents_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font);
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        table_techs = new QTableWidget(groupBox_3);
        if (table_techs->columnCount() < 5)
            table_techs->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_techs->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_techs->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_techs->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_techs->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_techs->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        table_techs->setObjectName(QString::fromUtf8("table_techs"));
        table_techs->setStyleSheet(QString::fromUtf8("QTableWidget {background-image: url(:/ico/PNG/64/Gnome-System-Users-64.png);\n"
"background-repeat:no-repeat;\n"
"background-attachment:fixed;\n"
"background-position:bottom right; \n"
"text-align:left;}"));
        table_techs->setFrameShape(QFrame::Box);
        table_techs->setLineWidth(0);
        table_techs->setShowGrid(false);
        table_techs->setSortingEnabled(true);
        table_techs->horizontalHeader()->setStretchLastSection(true);
        table_techs->verticalHeader()->setVisible(false);

        verticalLayout_6->addWidget(table_techs);

        lbl_techs_error = new QLabel(groupBox_3);
        lbl_techs_error->setObjectName(QString::fromUtf8("lbl_techs_error"));

        verticalLayout_6->addWidget(lbl_techs_error);


        verticalLayout_5->addWidget(groupBox_3);

        dock_techs->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dock_techs);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuWindows->menuAction());
        menuFile->addAction(actionSettings);
        menuFile->addAction(action_Quit);
        menuFile->addSeparator();
        menuFile->addAction(actionReload_Network);
        menuFile->addAction(actionAbout);
        menuWindows->addAction(actionNetwork_Browser);
        menuWindows->addAction(actionTechs);

        retranslateUi(MainWindow);
        QObject::connect(actionSettings, SIGNAL(triggered()), MainWindow, SLOT(ShowSettings()));
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindow, SLOT(Quit()));
        QObject::connect(actionReload_Network, SIGNAL(triggered()), MainWindow, SLOT(LoadZone()));
        QObject::connect(actionAbout, SIGNAL(triggered()), MainWindow, SLOT(ShowAbout()));
        QObject::connect(dock_network_browser, SIGNAL(visibilityChanged(bool)), MainWindow, SLOT(NetworkVisibilityChanged(bool)));
        QObject::connect(actionNetwork_Browser, SIGNAL(toggled(bool)), dock_network_browser, SLOT(setVisible(bool)));
        QObject::connect(actionTechs, SIGNAL(toggled(bool)), dock_techs, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Metropark Pulse", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings...", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        actionReload_Network->setText(QApplication::translate("MainWindow", "Reload Network", 0, QApplication::UnicodeUTF8));
        actionFont_Size->setText(QApplication::translate("MainWindow", "Font Size", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", 0, QApplication::UnicodeUTF8));
        actionNetwork_Browser->setText(QApplication::translate("MainWindow", "Network", 0, QApplication::UnicodeUTF8));
        actionTechs->setText(QApplication::translate("MainWindow", "Who's Working What", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Hot Tickets", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = table_tickets->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Priority", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = table_tickets->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Ticket", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = table_tickets->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Owned By", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = table_tickets->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Working", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = table_tickets->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Worked Time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = table_tickets->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Customer", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = table_tickets->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Ticket Description", 0, QApplication::UnicodeUTF8));
        lbl_tickets_error->setText(QApplication::translate("MainWindow", "Loading...", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "System", 0, QApplication::UnicodeUTF8));
        menuWindows->setTitle(QApplication::translate("MainWindow", "Windows", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Network", 0, QApplication::UnicodeUTF8));
        lbl_zone_error->setText(QApplication::translate("MainWindow", "Loading...", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Who's Working What", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = table_techs->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Tech", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = table_techs->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Priority", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = table_techs->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Time Worked", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = table_techs->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Customer", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = table_techs->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Ticket Working", 0, QApplication::UnicodeUTF8));
        lbl_techs_error->setText(QApplication::translate("MainWindow", "Loading...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
