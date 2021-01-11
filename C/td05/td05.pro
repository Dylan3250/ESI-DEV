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

HEADERS += \
        slcircularlist_utility.h \
        slcircularlist.h \
        slnode_utility.h \
        slnode.h \
        value_t.h

SOURCES += \
        main.c \
        slcircularlist.c \
        slcircularlist_utility.c \
        slnode.c \
        slnode_utility.c
