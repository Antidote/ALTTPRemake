TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
    libzelda \
    Sakura \
    ALTTPRemake

Sakura.depends += libzelda
ALTTPRemake.depends += libzelda \
    Sakura
