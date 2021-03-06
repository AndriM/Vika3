#-------------------------------------------------
#
# Project created by QtCreator 2014-12-12T12:20:17
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    baserepository.cpp \
    computer.cpp \
    computerrepository.cpp \
    scienceservice.cpp \
    scientist.cpp \
    scientistrepository.cpp \
    scientistbase.cpp \
    computerbase.cpp \
    computeradd.cpp \
    connection.cpp \
    scientistadd.cpp \
    displayconnection.cpp \
    scientistconnect.cpp \
    displaysciconnection.cpp \
    displayscientist.cpp \
    removeconfirm.cpp

HEADERS  += mainwindow.h \
    baserepository.h \
    computer.h \
    computerrepository.h \
    scienceservice.h \
    scientist.h \
    scientistrepository.h \
    scientistbase.h \
    computerbase.h \
    computeradd.h \
    connection.h \
    scientistadd.h \
    displayconnection.h \
    scientistconnect.h \
    displaysciconnection.h \
    displayscientist.h \
    removeconfirm.h


FORMS    += mainwindow.ui \
    scientistbase.ui \
    computerbase.ui \
    computeradd.ui \
    connection.ui \
    scientistadd.ui \
    displayconnection.ui \
    scientistconnect.ui \
    displaysciconnection.ui \
    displayscientist.ui \
    removeconfirm.ui

OTHER_FILES += \
    science_db.sqlite \
    MunaAdSetjaSqliteSkrannaIBuildMoppuna.txt \
    untitled.pro.user

RESOURCES += \
    Icons.qrc
