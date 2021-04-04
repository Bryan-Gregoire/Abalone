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
    view/view.cpp


-std=c++17 -pedantic-errors -Wall -Wuninitialized


HEADERS += \
    controller/controller.h \
    model/board.h \
    model/color.h \
    model/game.h \
    model/gameStatus.h \
    model/hexagone.h \
    model/marble.h \
    model/player.h \
    model/playerStatus.h \
    model/model.h \
    model/utils/observable.h \
    model/utils/observer.h \
    view/view.h
