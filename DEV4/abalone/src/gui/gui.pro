QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../../config.pri)

SOURCES += \
    main.cpp \
    libs/ghexacell.cpp \
    view/view.cpp \
    controller/controller.cpp

HEADERS += \
    libs/ghexacell.h \
    view/view.h \
    controller/controller.h

FORMS += \
    view.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
