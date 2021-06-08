TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++14

SOURCES += \
    main.cpp \
    data.cpp \
    monomial.cpp \
    polynomial.cpp \

HEADERS += \
    data.h \
    function.h \
    monomial.h \
    polynomial.h \
    random/random.hpp
