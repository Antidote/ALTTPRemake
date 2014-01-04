TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L../libzelda/lib

QMAKE_CXXFLAGS += -std=c++0x -Os


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
        -lsfml-system \
        -lGL \
        -llua

INCLUDEPATH += \
    ../libzelda/include \
    include

SOURCES += main.cpp \
    SSpriteFrame.cpp \
    SSpriteFile.cpp \
    SSprite.cpp \
    SSpritePart.cpp \
    SSpriteFileWriter.cpp \
    SSpriteFileReader.cpp \
    Entity.cpp \
    RoundedRectangleShape.cpp

HEADERS += \
    SSpriteFrame.hpp \
    SSpriteFile.hpp \
    SSprite.hpp \
    SSpritePart.hpp \
    SSpriteFileWriter.hpp \
    SSpriteFileReader.hpp \
    Entity.hpp \
    RoundedRectangleShape.hpp

