#-------------------------------------------------
#
# Project created by QtCreator 2016-11-11T02:48:57
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dotandbox_1_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game_window.cpp \
    map_graphics.cpp

HEADERS  += mainwindow.h \
    game_window.h \
    map_graphics.h

FORMS    += mainwindow.ui \
    game_window.ui

RESOURCES += \
    res.qrc

