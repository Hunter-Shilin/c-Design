#-------------------------------------------------
#
# Project created by QtCreator 2020-09-11T13:34:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cpp_Dsign
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    chessboard.cpp \
    pattern.cpp

HEADERS += \
        mainwindow.h \
    chessboard.h \
    pattern.h

FORMS += \
        mainwindow.ui \
    chessboard.ui \
    pattern.ui

DISTFILES += \
    ../Saved Pictures/93574947290570165.jpg \
    ../Saved Pictures/314219477136484741.jpg \
    ../Saved Pictures/bk.jpg \
    ../Saved Pictures/chessboard_bg.jpg \
    ../Saved Pictures/chessboard_bg1.jpg \
    ../Saved Pictures/timg.jpg

RESOURCES += \
    image.qrc

