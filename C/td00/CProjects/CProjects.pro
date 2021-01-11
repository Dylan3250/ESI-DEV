TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c99 \
-pedantic-errors \
-D__USE_MINGW_ANSI_STDIO

QMAKE_CFLAGS += -std=c11 \
-pedantic-errors \
-D__USE_MINGW_ANSI_STDIO

SOURCES += \
        main.c \
        test.c

HEADERS += \
    test.h
