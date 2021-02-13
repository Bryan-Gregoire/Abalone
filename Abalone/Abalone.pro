TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    Board.h \
    Color.h \
    Direction.h \
    Game.h \
    GameStatus.h \
    Hexagone.h \
    Marble.h \
    Player.h \
    PlayerStatus.h \
    Position.h
