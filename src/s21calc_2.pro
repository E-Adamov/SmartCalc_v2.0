QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    s21controller.cc \
    s21model.cc \
    cred_calc.cc \
    main.cc \
    s21view.cc \
    qcustomplot.cpp

HEADERS += \
    s21controller.h \
    s21model.h \
    cred_calc.h \
    s21view.h \
    qcustomplot.h

FORMS += \
    cred_calc.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
