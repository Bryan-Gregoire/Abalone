TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        observable.cpp

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
