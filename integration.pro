QT       += core gui sql printsupport
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Candidat.cpp \
    GereCandidat.cpp \
    connection.cpp \
    employe.cpp \
    employeSQL.cpp \
    geremoniteur.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    moniteur.cpp \
    veh.cpp \
    vehSQL.cpp
HEADERS += \
    Candidat.h \
    GereCandidat.h \
    connection.h \
    employe.h \
    employeSQL.h \
    geremoniteur.h \
    login.h \
    mainwindow.h \
    moniteur.h \
    veh.h \
    vehSQL.h
FORMS += \
    mainwindow.ui\
    login.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += resource.qrc \
    candidat.qrc \
    excel.qrc \
    img.qrc \
    pdf.qrc
