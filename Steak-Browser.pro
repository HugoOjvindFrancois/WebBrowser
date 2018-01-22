QT       += core gui webenginewidgets webengine

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "steak-browser"
TEMPLATE = app

SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/settingdialog.cpp

FORMS += \
    form/mainwindow.ui \
    form/settingdialog.ui

HEADERS += \
    header/mainwindow.h \
    header/settingdialog.h
