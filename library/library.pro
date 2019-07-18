#-------------------------------------------------
#
# Project created by QtCreator 2014-06-24T16:45:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = library
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    book.cpp \
    booklist.cpp \
    clientlist.cpp \
    issuedbooks.cpp \
    filewriter.cpp \
    readfromfile.cpp

HEADERS  += mainwindow.h \
    client.h \
    book.h \
    booklist.h \
    clientlist.h \
    issuedbooks.h \
    filewriter.h \
    readfromfile.h

FORMS    += mainwindow.ui
