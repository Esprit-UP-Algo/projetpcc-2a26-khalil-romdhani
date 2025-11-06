QT       += core gui widgets sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    connection.cpp \
    employe.cpp \
    gereremploye.cpp \
    main.cpp \
    mainwindow.cpp \
    login.cpp

HEADERS += \
    GereEmploye.h \
    connection.h \
    employe.h \
    mainwindow.h \
    login.h

FORMS += \
    mainwindow.ui \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    candidat.qrc \
    excel.qrc \
    img.qrc \
    pdf.qrc
