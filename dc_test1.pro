# -------------------------------------------------
# Project created by QtCreator 2009-03-07T14:54:40
# -------------------------------------------------
QT += network \
    xml
TARGET = dc_test1
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    hubconnection.cpp \
    hubnicklist.cpp \
    tablemodel.cpp \
    filemanager.cpp \
    tth/tiger_data.c \
    tth/tiger.c \
    tth/hashfile.cpp \
    tth/hash.cpp \
    tth/base32.cpp
HEADERS += mainwindow.h \
    hubconnection.h \
    global.h \
    hubnicklist.h \
    tablemodel.h \
    filemanager.h \
    tth/tiger.h \
    tth/hashfile.h \
    tth/hash.h \
    tth/byte_order.h \
    tth/base32.h
FORMS += mainwindow.ui
