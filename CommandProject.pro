TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    clients.cpp \
    other.cpp \
    expenses.cpp \
    orders.cpp

HEADERS += \
    clients.h \
    typefio.h \
    other.h \
    expenses.h \
    orders.h
