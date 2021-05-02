TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

include(../../config.pri)

HEADERS += \
    controller/controller.h \
    view/view.h

SOURCES += \
        controller/controller.cpp \
        main/main.cpp \
        view/view.cpp
