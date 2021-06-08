TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17

SOURCES += \
    main.cpp

HEADERS += \
    random.hpp

QMAKE_CXXFLAGS += -pedantic-errors -Wall
