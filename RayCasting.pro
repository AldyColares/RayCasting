#-------------------------------------------------
#
# Project created by QtCreator 2016-10-25T19:25:43
#
#-------------------------------------------------

QT       += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RayCasting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loadmaterial.cpp \
    crossproduct.cpp \
    coordinatetransformation.cpp \
    scenarioobject.cpp \
    dot.cpp \
    generatevetor.cpp

HEADERS  += mainwindow.h \
    loadmaterial.h \
    crossproduct.h \
    scalarproduct.h \
    coordinatetransformation.h \
    scenarioobject.h \
    dot.h \
    face3d.h \
    point3d.h \
    generatevetor.h

FORMS    += mainwindow.ui
