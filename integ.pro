QT   += core gui sql printsupport charts network serialport widgets axcontainer
greaterThan(QT_MAJOR_VERSION, 4):
CONFIG += c++17

SOURCES += \
    Candidat.cpp \
    GereCandidat.cpp \
    StatCandidat.cpp \
    arduino.cpp \
    arduinomanager.cpp \
    chatbot.cpp \
    connection.cpp \
    employe.cpp \
    employeSQL.cpp \
    geremoniteur.cpp \
    gereseance.cpp \
    gestionseanceui.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    moniteur.cpp \
    FeedbackUtilisateur.cpp \
    ImageVer_C.cpp \
    JournalCandidat.cpp \
    cartegrisedialog.cpp \
    groq_manager.cpp \
    groq_predictor.cpp \
    seance.cpp \
    smtp.cpp \
    statistics.cpp \
    veh.cpp \
    vehChart.cpp \
    vehSQL.cpp \
    veh_func.cpp

HEADERS += \
    Candidat.h \
    GereCandidat.h \
    StatCandidat.h \
    arduino.h \
    arduinomanager.h \
    chatbot.h \
    connection.h \
    employe.h \
    employeSQL.h \
    geremoniteur.h \
    gereseance.h \
    gestionseanceui.h \
    login.h \
    mainwindow.h \
    moniteur.h \
    seance.h \
    smtp.h \
    statistics.h \
    veh.h \
    vehSQL.h \
    FeedbackUtilisateur.h \
    ImageVer_C.h \
    JournalCandidat.h \
    cartegrisedialog.h \
    groq_config.h \
    groq_manager.h \
    groq_predictor.h \
    vehChart.h \
    veh_func.h

FORMS += \
    mainwindow.ui \
    login.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
