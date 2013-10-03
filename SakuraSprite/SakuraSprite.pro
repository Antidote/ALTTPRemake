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

INCLUDEPATH += \
    ../libzelda/include \
    include

SOURCES += main.cpp \
    SSpriteFrame.cpp \
    SSPritePart.cpp \
    SSpriteFile.cpp

HEADERS += \
    SSpriteFrame.hpp \
    SSPritePart.hpp \
    SSpriteFile.hpp

