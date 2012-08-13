#-------------------------------------------------
#
# Project created by QtCreator 2012-07-31T11:50:59
#
#-------------------------------------------------

QT       += core gui network

TARGET = Pulse
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    namerecord.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    namerecord.h \
    soci-3.1.0/core/soci.h \
    settings.h

FORMS    += mainwindow.ui \
    settings.ui

RESOURCES += \
    Resources.qrc

LIBS += \
    -L$$PWD\\soci-3.1.0\\build\\lib \
    -lsoci_core_3_1
