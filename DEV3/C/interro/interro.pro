TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG+=sdk_no_version_check

QMAKE_CFLAGS += -std=c99 \
-pedantic-errors \
-D__USE_MINGW_ANSI_STDIO

QMAKE_CFLAGS += -std=c11 \
-pedantic-errors \
-D__USE_MINGW_ANSI_STDIO

SOURCES += \
        forstudent/util.c \
        imo.c \
        main.c

HEADERS += \
    forstudent/util.h \
    imo.h

