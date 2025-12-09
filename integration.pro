QT       += core gui sql printsupport concurrent axcontainer serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# === SOURCES ET HEADERS ===
SOURCES += \
    ArduinoManager.cpp \
    Candidat.cpp \
    GereCandidat.cpp \
    JournalCandidat.cpp \
    StatCandidat.cpp \
    ImageVer_C.cpp \
    FeedbackUtilisateur.cpp \
    arduino.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ArduinoManager.h \
    Candidat.h \
    GereCandidat.h \
    JournalCandidat.h \
    StatCandidat.h \
    ImageVer_C.h \
    FeedbackUtilisateur.h \
    arduino.h \
    connection.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resource.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
