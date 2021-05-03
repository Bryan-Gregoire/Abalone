TEMPLATE = subdirs

SUBDIRS += \
    src/abalonecore \
    src/gui \
    src/tui

src-tui.depends = src/abalonecore

OTHER_FILES += config.pri
