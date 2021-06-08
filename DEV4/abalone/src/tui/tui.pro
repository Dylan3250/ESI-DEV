TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

include(../../config.pri)

SOURCES += \
    controller/controller.cpp \
    main.cpp \
    view/view.cpp \

HEADERS += \
    controller/controller.h \
    view/view.h \
    ../../libs/consoleColor.h
