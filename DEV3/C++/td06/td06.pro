TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += \
    main.cpp \
    mathesi.cpp \
    surcharge_02.cpp \
    surcharge_03.cpp \
    surcharge_01.cpp \
    surcharge_04.cpp

HEADERS += \
    mathesi.h

QMAKE_CXXFLAGS += -pedantic-errors -Wall
