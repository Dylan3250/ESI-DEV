TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++14

SOURCES += \
    draw.cpp \
    data/data.cpp \
    lotto.cpp \
    main.cpp \
    pronostic.cpp

HEADERS += \
    draw.h \
    lotto.h \
    main.h \
    pronostic.h \
    random/random.hpp \
    data/data.h