#-------------------------------------------------
#
# Project created by QtCreator 2016-05-26T18:30:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Music_Browser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    winGenArtistLib.cpp \
    wArtist.cpp


HEADERS  += mainwindow.h \
    winGenArtistLib.h \
    wArtist.h

FORMS    += mainwindow.ui \
    winGenArtistLib.ui

RESOURCES += \
    src.qrc

win32: LIBS += -L$$PWD/./ -ltaglib

INCLUDEPATH += $$PWD/taglib
DEPENDPATH += $$PWD/taglib

win32: LIBS += -L$$PWD/./ -ltaglib

INCLUDEPATH += $$PWD/taglib
DEPENDPATH += $$PWD/taglib

INCLUDEPATH += $$PWD/taglib/ape
DEPENDPATH += $$PWD/taglib/ape

INCLUDEPATH += $$PWD/taglib/asf
DEPENDPATH += $$PWD/taglib/asf

INCLUDEPATH += $$PWD/taglib/flac
DEPENDPATH += $$PWD/taglib/flac

INCLUDEPATH += $$PWD/taglib/it
DEPENDPATH += $$PWD/taglib/it

INCLUDEPATH += $$PWD/taglib/mod
DEPENDPATH += $$PWD/taglib/mod

INCLUDEPATH += $$PWD/taglib/mp4
DEPENDPATH += $$PWD/taglib/mp4

INCLUDEPATH += $$PWD/taglib/mpc
DEPENDPATH += $$PWD/taglib/mpc

INCLUDEPATH += $$PWD/taglib/mpeg
DEPENDPATH += $$PWD/taglib/mpeg

INCLUDEPATH += $$PWD/taglib/ogg
DEPENDPATH += $$PWD/taglib/ogg

INCLUDEPATH += $$PWD/taglib/riff
DEPENDPATH += $$PWD/taglib/riff

INCLUDEPATH += $$PWD/taglib/s3m
DEPENDPATH += $$PWD/taglib/s3m

INCLUDEPATH += $$PWD/taglib/toolkit
DEPENDPATH += $$PWD/taglib/toolkit

INCLUDEPATH += $$PWD/taglib/trueaudio
DEPENDPATH += $$PWD/taglib/trueaudio

INCLUDEPATH += $$PWD/taglib/wavpack
DEPENDPATH += $$PWD/taglib/wavpack

INCLUDEPATH += $$PWD/taglib/xm
DEPENDPATH += $$PWD/taglib/xm
