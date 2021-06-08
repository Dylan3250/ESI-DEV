TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17

SOURCES += \
    data_fraction.cpp \
    fraction.cpp \
    main.cpp

HEADERS += \
    data_fraction.h \
    fraction.h \
    fraction_constexpr.h \
    random.hpp \
    sign.h

QMAKE_CXXFLAGS += -std=c++17 -pedantic-errors -Wall
