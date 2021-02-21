QT       += core gui network mqtt sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

HEADERS = \
   $$PWD/login.h \
   chat.h \
   databaseconnection.h \
   editprofile.h \
   homepage.h \
   mainwindow.h \
   uploadpic.h \
   user.h

SOURCES = \
   $$PWD/main.cpp \
   $$PWD/login.cpp \
   User.cpp \
   chat.cpp \
   databaseconnection.cpp \
   editprofile.cpp \
   homepage.cpp \
   mainwindow.cpp \
   uploadpic.cpp

FORMS = \
   $$PWD/login.ui \
   editprofile.ui \
   mainwindow.ui \
   uploadpic.ui


INCLUDEPATH = \
    $$PWD/.

#DEFINES =

RESOURCES += \
    src.qrc
