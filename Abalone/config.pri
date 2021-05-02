CONFIG += c++17

CONFIG -= debug_and_release debug_and_release_target

INCLUDEPATH += $${PWD}/libs/

CORELIBMODE=staticlib

!equals(TARGET, abalonecore) {
    include($${PWD}/src/abalonecore/abalonecore.pri)
}

QMAKE_CXXFLAGS += -Wall

lessThan(QT_MAJOR_VERSION, 5) {
    error("use Qt 5 or newer")
}

lessThan(QT_MINOR_VERSION, 12) {
    QMAKE_CXXFLAGS += -std=c++17
}
