#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingsDialog(QWidget *parent = 0);
    void SaveSettings();
    ~SettingsDialog();
    
private:
    void LoadSettings();
    Ui::Settings *ui;
public slots:
    void AddZone();
    void RemoveSelectedZone();
    void AddService();
    void RemoveSelectedService();
};

#endif // SETTINGS_H
