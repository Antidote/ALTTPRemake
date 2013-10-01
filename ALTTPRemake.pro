TEMPLATE = subdirs

Sakura.depends += libzelda
ALTTPRemake.depends += libzelda \
    Sakura

SUBDIRS += \
    libzelda \
    Sakura\
    ALTTPRemake
