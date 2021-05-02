TEMPLATE = subdirs

SUBDIRS += \
    src/abalonecore \
    src/tui

src-tui.depends = src/abalonecore

OTHER_FILES += config.pri
