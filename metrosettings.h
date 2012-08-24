#ifndef METROSETTINGS_H
#define METROSETTINGS_H

#include <QSettings>

class MetroSettings : public QSettings
{
      Q_OBJECT
   public:
      explicit MetroSettings(QObject *parent = 0);
      
   signals:
      
   public slots:
      
};

#endif // METROSETTINGS_H
