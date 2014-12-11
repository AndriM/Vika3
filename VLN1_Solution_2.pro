#-------------------------------------------------
#
# Project created by QtCreator 2014-11-15T13:55:58
#
#-------------------------------------------------

QT       += core sql

QT       -= gui

TARGET = VLN1_Solution_2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    scientistrepository.cpp \
    scientist.cpp \
    consoleui.cpp \
    scienceservice.cpp \
    baserepository.cpp \
    computerrepository.cpp \
    computer.cpp \
    scientistcomputerconnections.cpp \
    scientistcomputerconnectionsrepository.cpp

HEADERS += \
    scientistrepository.h \
    scientist.h \
    consoleui.h \
    scienceservice.h \
    menus.h \
    baserepository.h \
    computerrepository.h \
    computer.h \
    scientistcomputerconnections.h \
    scientistcomputerconnectionsrepository.h
