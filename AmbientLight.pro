#-------------------------------------------------
#
# Project created by QtCreator 2010-10-05T17:02:20
#
#-------------------------------------------------

QT       += core gui

TARGET = AmbientLight
TEMPLATE = app


SOURCES += main.cpp\
        ambient_light_window.cpp

HEADERS  += ambient_light_window.h

FORMS    += ambient_light_window.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe45322e6
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
