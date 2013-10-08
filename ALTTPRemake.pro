TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
    libzelda \
    Sakura\
    ALTTPRemake \
    SakuraSprite

Sakura.depends += libzelda
ALTTPRemake.depends += libzelda \
    Sakura
