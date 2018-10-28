#-------------------------------------------------
#
# Project created by QtCreator 2017-12-24T10:00:41
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LevelBuilder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphicsscene.cpp \
    normalblock.cpp \
    solidblock.cpp \
    screenitem.cpp \
    levels.cpp

HEADERS  += mainwindow.h \
    graphicsscene.h \
    normalblock.h \
    solidblock.h \
    screenitem.h \
    levels.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
