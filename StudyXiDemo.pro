#-------------------------------------------------
#
# Project created by QtCreator 2016-08-06T15:12:33
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudyXiDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pushbutton.cpp \
    kaitou.cpp \
    find.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    pushbutton.h \
    kaitou.h \
    find.h \
    login.h

FORMS    += mainwindow.ui \
    kaitou.ui \
    find.ui \
    login.ui

RESOURCES += \
    tupian.qrc \
    tiku.qrc \
    font.qrc
CONFIG  += qaxcontainer

RC_FILE=icon.rc

QT += multimedia


