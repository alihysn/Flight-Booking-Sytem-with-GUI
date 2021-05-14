QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QT += widgets

QT += sql

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Hsearch.cpp \
    card.cpp \
    customer.cpp \
    customerlogin.cpp \
    findshortestpath.cpp \
    invoice.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    paymentmethod.cpp \
    rating.cpp \
    search.cpp \
    sflights.cpp \
    wallet.cpp

HEADERS += \
    Hsearch.h \
    card.h \
    customer.h \
    customerlogin.h \
    findshortestpath.h \
    invoice.h \
    mail.h \
    mainwindow.h \
    paymentmethod.h \
    rating.h \
    search.h \
    sflights.h \
    wallet.h

FORMS += \
    Hsearch.ui \
    customer.ui \
    customerlogin.ui \
    mail.ui \
    mainwindow.ui \
    sflights.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
