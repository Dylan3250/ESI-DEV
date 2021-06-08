TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++17

SOURCES += \
    data.cpp \
    main.cpp


HEADERS += \
    data.h \
    duration.h \
    main.h \
    sign.h \
    random/random.hpp
