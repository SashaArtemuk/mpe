#-------------------------------------------------
#
# Project created by QtCreator 2017-10-28T16:00:18
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = parser_2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    elems/Celement.cpp \
    elems/Element.cpp \
    elems/Melements.cpp \
    elems/Stackelement.cpp \
    elems/Velement.cpp \
    funcs/AbstractF.cpp \
    funcs/Compare.cpp \
    funcs/CustomFunc.cpp \
    funcs/Logical.cpp \
    funcs/sincos.cpp \
    funcs/StandartFunctions.cpp \
    Calculator.cpp \
    collection.cpp \
    Compilator.cpp \
    Parser.cpp \
    variablesdialog.cpp \
    savedialog.cpp \
    setargs.cpp \
    grafik.cpp \
    ogl.cpp \
    coord.cpp

HEADERS  += mainwindow.h \
    elems/Celement.h \
    elems/Element.h \
    elems/Melements.h \
    elems/Stackelement.h \
    elems/Velement.h \
    funcs/AbstractF.h \
    funcs/Compare.h \
    funcs/CustomFunc.h \
    funcs/Logical.h \
    funcs/Sincos.h \
    funcs/StandartFunctions.h \
    Calculator.h \
    collection.h \
    Compilator.h \
    Exceptions.h \
    Parser.h \
    variablesdialog.h \
    savedialog.h \
    setargs.h \
    grafik.h \
    ogl.h \
    coord.h

FORMS    += mainwindow.ui \
    variablesdialog.ui \
    savedialog.ui \
    setargs.ui \
    grafik.ui

LIBS += -lglu32 -lopengl32

QMAKE_TARGET_COMPANY = "Oleksandr Artemuk"
QMAKE_TARGET_PRODUCT = "PME"
QMAKE_TARGET_COPYRIGHT = "2017 PME Oleksandr Artemuk"
VERSION = 1.0.0.0
QMAKE_TARGET_DESCRIPTION = "Parser of Mathematical Expressions"

QMAKE_CXXFLAGS_RELEASE -= -O4
QMAKE_CXXFLAGS_RELEASE -= -O3
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE -= -O0
QMAKE_CXXFLAGS_RELEASE += -O0

