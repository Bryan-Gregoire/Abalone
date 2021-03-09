TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
SOURCES += \
    controller/controller.cpp \
    main/main.cpp \
    model/board.cpp \
    model/game.cpp \
    model/observable.cpp \
    view/interfaceView.cpp \
    view/view.cpp


-std=c++17 -pedantic-errors -Wall -Wuninitialized


HEADERS += \
    controller/controller.h \
    model/Board.h \
    model/Color.h \
    model/Direction.h \
    model/Game.h \
    model/GameStatus.h \
    model/Hexagone.h \
    model/Marble.h \
    model/Player.h \
    model/PlayerStatus.h \
    model/Position.h \
    model/model.h \
    model/utils/observable.h \
    model/utils/observer.h \
    view/interfaceView.h \
    view/view.h
