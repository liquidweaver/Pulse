#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    void SaveSettings();
    ~Settings();
    
private:
    void LoadSettings();
    Ui::Settings *ui;
};

#endif // SETTINGS_H
