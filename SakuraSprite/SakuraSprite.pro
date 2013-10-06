TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L../libzelda/lib

QMAKE_CXXFLAGS += -std=c++0x


CONFIG(release, release|debug){
    DEFINES -= DEBUG
    OBJECTS_DIR += release.objs
    TARGET = sakurasprite
    LIBS +=  -lzelda
}

CONFIG(debug, debug|release){
    DEFINES += DEBUG
    OBJECTS_DIR += debug.objs
    TARGET = sakurasprite-d
    LIBS += -lzelda-d
}

LIBS += -lsfml-graphics \
        -lsfml-window \
        -lsfml-system

INCLUDEPATH += \
    ../libzelda/include \
    include

SOURCES += main.cpp \
    SSpriteFrame.cpp \
    SSpriteFile.cpp \
    SSprite.cpp \
    SSpritePart.cpp

HEADERS += \
    SSpriteFrame.hpp \
    SSpriteFile.hpp \
    SSprite.hpp \
    SSpritePart.hpp

