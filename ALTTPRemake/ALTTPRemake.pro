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
        -lz \
        -ltinyxml


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
    src/SakuraSplash.cpp \
    src/Button.cpp \
    src/MenuState.cpp \
    src/MainMenu.cpp

HEADERS += \
    include/ALTTPEngine.hpp \
    include/Link.hpp \
    include/ALTTPGameState.hpp \
    include/SplashState.hpp \
    include/SFMLSplash.hpp \
    include/SakuraSplash.hpp \
    include/Button.hpp \
    include/MenuState.hpp \
    include/MainMenu.hpp

OTHER_FILES += \
    data/console/bg2.png \
    data/console/bg1.png \
    data/fonts/debug.ttf \
    data/fonts/cour.ttf \
    data/fonts/arial.ttf \
    data/fonts/RetGanon.ttf \
    data/maps/EasternPalace.zmap \
    data/music/hyrule_castle.ogg \
    data/sounds/LTTP_Rupee1.wav \
    data/sounds/LTTP_Pause_Open.wav \
    data/sounds/LTTP_Pause_Close.wav \
    data/sounds/LTTP_Link_Hurt.wav \
    data/sounds/LTTP_Item.wav \
    data/splash/Wiiking.png \
    data/splash/SakuraLogo.png \
    data/splash/SFML.png \
    data/splash/NintendoLogo.png \
    data/sprites/Link/link_green.png \
    data/sprites/Link/Link.sprs \
    data/gui/testButton.png \
    data/gui/hud_life.png

