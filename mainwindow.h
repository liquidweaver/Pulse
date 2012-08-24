#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QSystemTrayIcon>
#include <QMap>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include "namerecord.h"
#include "service.h"
#include <ctime>
#include "global_defines.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void SaveSetting( const QString& path, const QVariant& value );
    QVariant LoadSetting( const QString& path );
    
private:
    void AddRecord( NameRecord& );
    void ZoneTransfer( const QString&, QList<NameRecord>& );
    QString GrabZoneSOA( const QString& );
    QString RunExternal( const QString&, const QString& );
    void SetServiceLocation(const QString &service_name);
    Ui::MainWindow *ui;
    QSystemTrayIcon* m_tray_icon;
    void SaveServices( const QMap<QString,Service>& service_map );
    QMap<QString, Service> LoadServices();
    QTimer m_ticket_timer, m_zone_timer, m_techs_timer;
    bool m_show_close_warning;
    QDateTime QDateTimeFromTM(std::tm& t );
    void LoadDefaultSettings();

public slots:
    void LoadTickets();
    void LoadTechs();
    void LoadZones();
    void ShowAbout();
    void ShowTheatre( bool );
    void service_link_handler( const QString& link );
    void service_url_handler( const QUrl& url );
    void ShowSettings();
    void Quit();
    void closeEvent(QCloseEvent *event);
    void showNormal();
    void TrayClicked(QSystemTrayIcon::ActivationReason);
    void NetworkVisibilityChanged(bool);
    void TechVisibilityChanged(bool);
};

#endif // MAINWINDOW_H
