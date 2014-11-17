#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T22:39:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PRJ3-GUI
TEMPLATE = app


SOURCES += main.cpp \
    winMain.cpp \
    caddremove.cpp \
    cconfig.cpp \
    winConfig.cpp \
    UI.cpp \
    conoff.cpp

HEADERS  += \
    winMain.h \
    caddremove.h \
    cconfig.h \
    winConfig.h \
    UI.h \
    conoff.h

FORMS    += \
    winMain.ui \
    winConfig.ui
