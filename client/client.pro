#-------------------------------------------------
#
# Project created by QtCreator 2014-05-16T14:58:11
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp \
    ui/mainwidget.cpp \
    ui/tablewidget.cpp \
    entities/employee.cpp \
    entities/link.cpp \
    entities/manager.cpp \
    entities/task.cpp \
    tables/tables.cpp

HEADERS  += \
    ui/tablewidget.h \
    ui/mainwidget.h \
    entities/employee.h \
    entities/entities.h \
    entities/ientity.h \
    entities/ilink.h \
    entities/link.h \
    entities/manager.h \
    entities/task.h
