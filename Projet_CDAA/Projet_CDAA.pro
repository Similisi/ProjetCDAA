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
    cherchercontact.cpp \
    contact.cpp \
    contactbdd.cpp \
    contactinteraction.cpp \
    gestionhistorique.cpp \
    gestioninteraction.cpp \
    gestionnairecontact.cpp \
    gestiontache.cpp \
    historique.cpp \
    historiquebdd.cpp \
    interaction.cpp \
    interactionbdd.cpp \
    lancementbdd.cpp \
    main.cpp \
    mainwindow.cpp \
    modificationcontact.cpp \
    resultatcontact.cpp \
    tache.cpp

HEADERS += \
    addcontact.h \
    addinteraction.h \
    affhisto.h \
    affichageinteraction.h \
    cherchercontact.h \
    contact.h \
    contactbdd.h \
    contactinteraction.h \
    date.h \
    gestionhistorique.h \
    gestioninteraction.h \
    gestionnairecontact.h \
    gestiontache.h \
    historique.h \
    historiquebdd.h \
    interaction.h \
    interactionbdd.h \
    lancementbdd.h \
    mainwindow.h \
    modificationcontact.h \
    resultatcontact.h \
    tache.h

FORMS += \
    addcontact.ui \
    addinteraction.ui \
    affhisto.ui \
    affichageinteraction.ui \
    cherchercontact.ui \
    mainwindow.ui \
    modificationcontact.ui \
    resultatcontact.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
