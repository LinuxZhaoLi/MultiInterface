QT += core gui quick xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

OBJECTS_DIR = ./build/$$TARGET/obj
MOC_DIR	= ./build/$$TARGET/moc
DESTDIR	= ./


SOURCES += \
    main.cpp \
    test1.cpp \
    view.cpp \
    viewcontext.cpp \
    viewres.cpp

HEADERS += \
    test1.h \
    view.h \
    viewcontext.h \
    viewres.h



DISTFILES += \
    test.ini \
    qml_1.qml \
    qml_2.qml \
    qml_3.qml \
    qml_4.qml \
    qml_5.qml \
    qml_6.qml \
    views/qml_1.qml \
    views/qml_2.qml \
    views/qml_3.qml \
    views/qml_4.qml \
    views/qml_5.qml \
    views/qml_6.qml
