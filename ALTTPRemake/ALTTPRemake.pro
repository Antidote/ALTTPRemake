TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


LIBS += -L../libzelda/lib \
        -L../Sakura/lib

QMAKE_CXXFLAGS += -std=c++0x


CONFIG(release, release|debug){
    DEFINES -= DEBUG
    OBJECTS_DIR += release.objs
    TARGET = alttpremake
    LIBS += -lsakura \
            -lzelda
}

CONFIG(debug, debug|release){
    DEFINES += DEBUG
    OBJECTS_DIR += debug.objs
    TARGET = alttpremake-d
    LIBS += -lsakura-d \
            -lzelda-d
}

win32:LIBS += \
    -L../Sakura/extlibs/GLEW/lib \
    -L../Sakura/extlibs/SFML/lib \
    -L../Sakura/extlibs/AL/lib \
    -L../Sakura/extlibs/physfs/lib \
    -L../Sakura/extlibs/AL/lib \
    -lopenal32 \
    -lopengl32

unix:LIBS += \
    -lGL \
    -lGLEW \
    -lGLU \
    -lX11 \
    -lopenal

LIBS += -lsfml-graphics \
        -lsfml-window \
        -lsfml-audio \
        -lsfml-network \
        -lsfml-system \
        -lphysfs \
        -lz


INCLUDEPATH += \
               include \
               ../libzelda/include \
               ../Sakura/include

SOURCES += src/main.cpp \
    src/ALTTPEngine.cpp \
    src/Link.cpp \
    src/ALTTPGameState.cpp \
    src/SplashState.cpp \
    src/SFMLSplash.cpp \
    src/SakuraSplash.cpp

HEADERS += \
    include/ALTTPEngine.hpp \
    include/Link.hpp \
    include/ALTTPGameState.hpp \
    include/SplashState.hpp \
    include/SFMLSplash.hpp \
    include/SakuraSplash.hpp

