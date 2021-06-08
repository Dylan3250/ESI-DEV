CONFIG -= qt

TEMPLATE = lib

include(../../config.pri)

# CORELIBMODE (staticlib or sharedlib) is defined in the global config.pri.
CONFIG += $${CORELIBMODE}

SOURCES += \
    board.cpp \
    utils/observable.cpp

HEADERS += \
    actionStatus.h \
    ball.h \
    board.h \
    game.h \
    gameStatus.h \
    hexagon.h \
    model.h \
    player.h \
    position.h \
    utils/observable.h \
    utils/observer.h

DISTFILES += \
    abalonecore.pri
