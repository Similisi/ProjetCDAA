QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcontact.cpp \
    addinteraction.cpp \
    affhisto.cpp \
    affichageinteraction.cpp \
    contact.cpp \
    contactbdd.cpp \
    contactinteraction.cpp \
    gestioninteraction.cpp \
    gestionnairecontact.cpp \
    gestiontache.cpp \
    historique.cpp \
    interaction.cpp \
    interactionbdd.cpp \
    main.cpp \
    mainwindow.cpp \
    modificationcontact.cpp \
    tache.cpp

HEADERS += \
    addcontact.h \
    addinteraction.h \
    affhisto.h \
    affichageinteraction.h \
    contact.h \
    contactbdd.h \
    contactinteraction.h \
    date.h \
    gestioninteraction.h \
    gestionnairecontact.h \
    gestiontache.h \
    historique.h \
    interaction.h \
    interactionbdd.h \
    mainwindow.h \
    modificationcontact.h \
    tache.h

FORMS += \
    addcontact.ui \
    addinteraction.ui \
    affhisto.ui \
    affichageinteraction.ui \
    mainwindow.ui \
    modificationcontact.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
