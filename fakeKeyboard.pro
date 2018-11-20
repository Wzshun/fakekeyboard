QT += gui-private widgets

TARGET = FakeKeyboardplugin
TEMPLATE = lib
CONFIG += plugin

DEFINES += FAKEKEYBOARD_LIBRARY

HEADERS += \
    keyboardplugin.h \
    inputcontext.h \
    fakekeyboard_global.h \
    inputview.h

SOURCES += \
    keyboardplugin.cpp \
    inputcontext.cpp \
    inputview.cpp

FORMS += \
    inputview.ui

DISTFILES += \
    fakeKeyboard.json
