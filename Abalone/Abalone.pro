TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
DEFINES += _x32 _OSX
SOURCES += \
        board.cpp \
        game.cpp \
        hexagone.cpp \
        main.cpp \
        observable.cpp

-std=c++17 -pedantic-errors -Wall -Wuninitialized


HEADERS += \
    board.h \
    color.h \
    direction.h \
    game.h \
    gameStatus.h \
    hexagone.h \
    marble.h \
    model.h \
    observable.h \
    player.h \
    playerStatus.h \
    position.h \
    utils/observable.h \
    utils/observer.h
