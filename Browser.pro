QT       += core gui webenginewidgets webengine

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "Steak Browser"
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    settingdialog.cpp

FORMS += \
    mainwindow.ui \
    settingdialog.ui

HEADERS += \
    mainwindow.h \
    settingdialog.h
