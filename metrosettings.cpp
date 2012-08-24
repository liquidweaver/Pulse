#include "metrosettings.h"

MetroSettings::MetroSettings(QObject *parent) :
   QSettings(QSettings::IniFormat, QSettings::UserScope,
             "metropark", "pulse", parent)
{

}
