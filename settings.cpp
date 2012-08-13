#include "settings.h"
#include "ui_settings.h"
#include <QSettings>
#include <QDir>
#include <QtGui>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    LoadSettings();

}

Settings::~Settings()
{
    delete ui;
}

void Settings::LoadSettings() {
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                            "metropark", "pulse");
    ui->edit_merp_host->setText( settings.value( "merp_host" ).toString() );
    ui->edit_zone->setText( settings.value( "dns_zone" ).toString() );
    ui->txt_config_path->setText(tr("<b>Configuration Path:</b><div style=\"margin-left: 64px;\">%0</div>").arg(QDir::toNativeSeparators(settings.fileName())));
}

void Settings::SaveSettings() {
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                            "metropark", "pulse");

    settings.setValue( "merp_host", ui->edit_merp_host->text() );
    settings.setValue( "dns_zone", ui->edit_zone->text() );
}
