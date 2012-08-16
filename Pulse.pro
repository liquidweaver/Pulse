#-------------------------------------------------
#
# Project created by QtCreator 2012-07-31T11:50:59
#
#-------------------------------------------------

QT       += core gui network
TEMPLATE = app
TARGET = Pulse



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

win32 {
	RC_FILE = pulse.rc
	LIBS += \
		-L$$PWD\\soci-3.1.0\\build\\lib \
		-lsoci_core_3_1
}


unix {
	LIBS += \
		$$PWD/soci-3.1.0/build/lib/libsoci_core.a \
		$$PWD/soci-3.1.0/build/lib/libsoci_postgresql.a
}
OTHER_FILES += \
    pulse.rc \
    pulse.ico \
    .gitignore \
    PNG/64/Gnome-Preferences-Desktop-Remote-Desktop-64.png \
    .gitignore
