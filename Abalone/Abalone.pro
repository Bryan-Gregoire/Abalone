TEMPLATE = app
CONFIG += #console c++17
CONFIG -= app_bundle
CONFIG -= qt
SOURCES += \
    controller/controller.cpp \
    main/main.cpp \
    model/board.cpp \
    model/game.cpp \
    model/observable.cpp \
    view/view.cpp

QMAKE_CXXFLAGS += -std=c++17 \
    -pedantic-errors \
    -Wall -Wuninitialized


HEADERS += \
    controller/controller.h \
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
    model/utils/observer.h \
    view/view.h
