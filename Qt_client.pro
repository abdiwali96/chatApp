QT       += core gui network mqtt sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

HEADERS = \
   $$PWD/login.h \
   chat.h \
   contentsearch.h \
   databaseconnection.h \
   editprofile.h \
   historyappwindow.h \
   homepage.h \
   mainwindow.h \
   uploadpic.h \
   user.h

SOURCES = \
   $$PWD/main.cpp \
   $$PWD/login.cpp \
   User.cpp \
   chat.cpp \
   contentsearch.cpp \
   databaseconnection.cpp \
   editprofile.cpp \
   historyappwindow.cpp \
   homepage.cpp \
   mainwindow.cpp \
   uploadpic.cpp

FORMS = \
   $$PWD/login.ui \
   contentsearch.ui \
   editprofile.ui \
   historyappwindow.ui \
   homepage.ui \
   mainwindow.ui \
   uploadpic.ui


INCLUDEPATH = \
    $$PWD/.

#DEFINES =

RESOURCES += \
    src.qrc
