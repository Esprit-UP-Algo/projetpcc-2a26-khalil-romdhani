QT       += core gui
QT += core gui widgets printsupport
QT += sql
QT += axcontainer

CONFIG += c++17
CONFIG += console

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    seance.cpp \
    gereseance.cpp

HEADERS += \
    mainwindow.h \
    connection.h \
    seance.h \
    gereseance.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    seance.qrc
