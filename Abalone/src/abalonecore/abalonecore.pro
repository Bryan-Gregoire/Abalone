CONFIG -= qt

TEMPLATE=lib

include(../../config.pri)

CONFIG += $${CORELIBMODE}

HEADERS += \
    model/Board.h \
    model/Color.h \
    model/Game.h \
    model/GameStatus.h \
    model/Hexagone.h \
    model/Marble.h \
    model/Player.h \
    model/PlayerStatus.h \
    model/model.h \
    model/utils/observable.h \
    model/utils/observer.h

SOURCES += \
        model/board.cpp \
        model/game.cpp \
        model/observable.cpp

DISTFILES += \
    abalonecore.pri
