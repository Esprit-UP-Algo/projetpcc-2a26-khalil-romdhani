QT       += core gui sql printsupport charts network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Candidat.cpp \
    FeedbackUtilisateur.cpp \
    GereCandidat.cpp \
    ImageVer_C.cpp \
    JournalCandidat.cpp \
    StatCandidat.cpp \
    cartegrisedialog.cpp \
    groq_manager.cpp \
    groq_predictor.cpp \
    login.cpp \
    main.cpp \
    connection.cpp \
    mainwindow.cpp \
    veh.cpp \
    vehChart.cpp \
    vehSQL.cpp \
    veh_func.cpp
HEADERS += \
    Candidat.h \
    FeedbackUtilisateur.h \
    GereCandidat.h \
    ImageVer_C.h \
    JournalCandidat.h \
    StatCandidat.h \
    cartegrisedialog.h \
    groq_config.h \
    groq_manager.h \
    groq_predictor.h \
    login.h \
    mainwindow.h \
    connection.h \
    veh.h \
    vehChart.h \
    vehSQL.h \
    veh_func.h
FORMS += \
    mainwindow.ui\
    login.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

QMAKE_CXXFLAGS += -Wno-deprecated-declarations
