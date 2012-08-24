#include "settings.h"
#include "ui_settings.h"
#include "settingsmodel.h"
#include "metrosettings.h"
#include <QDir>
#include <QtGui>
#include "global_defines.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    LoadSettings();
    ServicesModel*  model = new ServicesModel();
    model->LoadServices();
    ui->tableView->setModel( model );
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    connect( ui->tableView, SIGNAL(doubleClicked(QModelIndex)),
             model, SLOT(SetFilePath(QModelIndex)) );
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::LoadSettings() {
    MetroSettings settings;
    ui->edit_merp_host->setText( settings.value( SETTING_MERP_HOST ).toString() );
    ui->edit_zone->setText( settings.value( SETTING_ZONE ).toString() );
    ui->edit_db_name->setText( settings.value( SETTING_DB_NAME ).toString());
    ui->edit_user->setText( settings.value( SETTING_DB_USER ).toString());
    ui->edit_pass->setText( settings.value( SETTING_DB_PASS ).toString());
    int size = settings.beginReadArray( "zones" );
    for ( int i=0; i<size; i++ ) {
       settings.setArrayIndex( i );
       QTableWidgetItem *new_item = new QTableWidgetItem( settings.value("name").toString(), Qt::DisplayRole );
       new_item->setFlags( new_item->flags () | Qt::ItemIsEditable );
       ui->list_services->insertRow(i);
       ui->list_services->setItem( i, 0, new_item );
    }
      settings.endArray();
    //ui->txt_config_path->setText(tr("<b>Configuration Path:</b><div style=\"margin-left: 64px;\">%0</div>").arg(QDir::toNativeSeparators(settings.fileName())));
}

void SettingsDialog::SaveSettings() {
    { MetroSettings settings;
      settings.setValue( SETTING_MERP_HOST, ui->edit_merp_host->text() );
      settings.setValue( SETTING_DB_NAME, ui->edit_db_name->text() );
      settings.setValue( SETTING_ZONE, ui->edit_zone->text() );
      settings.setValue( SETTING_DB_USER, ui->edit_user->text() );
      settings.setValue( SETTING_DB_PASS, ui->edit_pass->text() );

      settings.beginWriteArray( "zones" );
      for ( int i = 0; i < ui->list_services->rowCount(); i++ ) {
         settings.setArrayIndex( i );
         settings.setValue( "name" , ui->list_services->item( i, 0 )->data( Qt::DisplayRole ) );
      }
      settings.endArray();
    }
    ServicesModel *model = static_cast<ServicesModel *>(ui->tableView->model());
    model->SaveServices();
}

void SettingsDialog::AddService() {
    ServicesModel *model = static_cast<ServicesModel *>(ui->tableView->model());
    model->insertRow( model->rowCount() );
}

void SettingsDialog::AddZone() {
   QTableWidgetItem *new_item = new QTableWidgetItem( QString(""), Qt::DisplayRole );
   new_item->setFlags( new_item->flags () | Qt::ItemIsEditable );
   int i = ui->list_services->rowCount();
   ui->list_services->insertRow(i);
   ui->list_services->setItem( i, 0, new_item );
}

void SettingsDialog::RemoveSelectedService()
{
    ServicesModel *model = static_cast<ServicesModel *>(ui->tableView->model());
    // code to get list of selected rows
    QItemSelectionModel *selected = ui->tableView->selectionModel();
    QModelIndexList rowList = selected->selectedRows();

    // code to delete these model indexes from the model
    foreach(QModelIndex rowIndex, rowList) {
        model->removeRow(rowIndex.row(), rowIndex.parent());
    }

}

void SettingsDialog::RemoveSelectedZone() {

   //qDeleteAll(ui->list_services->selectedItems());

   // code to get list of selected rows
   QItemSelectionModel *selected = ui->list_services->selectionModel();
   QModelIndexList rowList = selected->selectedRows();

   // code to delete these model indexes from the model
   foreach(QModelIndex rowIndex, rowList) {
       ui->list_services->removeRow(rowIndex.row());
   }

}
