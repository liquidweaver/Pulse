#-------------------------------------------------
#
# Project created by QtCreator 2012-07-31T11:50:59
#
#-------------------------------------------------

QT       += core gui network

TARGET = Pulse
TEMPLATE = app
RC_FILE = pulse.rc


SOURCES += main.cpp\
        mainwindow.cpp \
    namerecord.cpp \
    settings.cpp \
    settingsmodel.cpp

HEADERS  += mainwindow.h \
    namerecord.h \
    soci-3.1.0/core/soci.h \
    settings.h \
    settingsmodel.h \
    service.h \
    global_defines.h

FORMS    += mainwindow.ui \
    settings.ui

RESOURCES += \
    Resources.qrc

LIBS += \
    -L$$PWD\\soci-3.1.0\\build\\lib \
    -lsoci_core_3_1

OTHER_FILES += \
    pulse.rc \
    pulse.ico \
    .gitignore
