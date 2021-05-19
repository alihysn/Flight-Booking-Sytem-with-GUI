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
    creditpay.cpp \
    customer.cpp \
    customerlogin.cpp \
    facilities.cpp \
    findshortestpath.cpp \
    flight.cpp \
    fsp.cpp \
    hotel.cpp \
    hotelreservation.cpp \
    invoice.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    paymentmethod.cpp \
    price.cpp \
    rating.cpp \
    ratingpage.cpp \
    room.cpp \
    search.cpp \
    sflights.cpp \
    trip.cpp \
    wallet.cpp

HEADERS += \
    Hsearch.h \
    card.h \
    creditpay.h \
    customer.h \
    customerlogin.h \
    facilities.h \
    findshortestpath.h \
    flight.h \
    fsp.h \
    hotel.h \
    hotelreservation.h \
    invoice.h \
    mail.h \
    mainwindow.h \
    paymentmethod.h \
    price.h \
    rating.h \
    ratingpage.h \
    room.h \
    search.h \
    sflights.h \
    trip.h \
    wallet.h

FORMS += \
    Hsearch.ui \
    creditpay.ui \
    customer.ui \
    customerlogin.ui \
    fsp.ui \
    hotelreservation.ui \
    mail.ui \
    mainwindow.ui \
    ratingpage.ui \
    sflights.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
