TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -pedantic-errors
SOURCES += \
        main.cpp \
        test.cpp

HEADERS += \
    test.h
