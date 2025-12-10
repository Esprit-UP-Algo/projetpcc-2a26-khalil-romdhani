QT += core gui sql printsupport charts network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    Candidat.cpp \
    GereCandidat.cpp \
    StatCandidat.cpp \
    arduino_comm.cpp \
    arduino_manager_s.cpp \
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
    arduino_comm.h \
    arduino_manager_s.h \
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

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
