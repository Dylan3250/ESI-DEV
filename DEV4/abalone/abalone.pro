TEMPLATE = subdirs
SUBDIRS += \
    src/gui \
    src/abalonecore \
    src/tui #\
    #tests

src-tui.depends = src/abalonecore
src-gui.depends = src/abalonecore
tests.depends = src/abalonecore

OTHER_FILES += \
    config.pri \
    ../README.md \
    ../.gitignore \
    ../.doxyfile
