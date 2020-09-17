#-------------------------------------------------
#
# Project created by QtCreator 2019-07-29T11:14:21
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtExercises
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Ex1/plotrandomwidget.cpp \
        Ex1/plotrandomworker.cpp \
        Ex1/threadexercises.cpp \
        Ex2/comboboxdelegate.cpp \
        Ex2/customcell.cpp \
        Ex2/datamodel.cpp \
        Ex2/tableexercise.cpp \
        Ex2/tablemodel.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        Ex1/iplot.h \
        Ex1/plotrandomwidget.h \
        Ex1/plotrandomworker.h \
        Ex1/threadexercises.h \
    Ex2/comboboxdelegate.h \
    Ex2/customcell.h \
    Ex2/datamodel.h \
    Ex2/tableexercise.h \
    Ex2/tablemodel.h \
        mainwindow.h \

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
