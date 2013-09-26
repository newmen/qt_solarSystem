QT += core gui opengl xml

LIBS += -lQGLViewer -lGLU

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    solarsystem.cpp \
    shape.cpp \
    sphere.cpp \
    iorbit.cpp \
    sun.cpp \
    timecounter.cpp \
    orbit.cpp \
    flatorbit.cpp \
    cube.cpp

HEADERS += \
    common.h \
    mainwindow.h \
    solarsystem.h \
    shape.h \
    sphere.h \
    ishapefactory.h \
    shapefactory.h \
    iorbit.h \
    sun.h \
    timecounter.h \
    orbit.h \
    flatorbit.h \
    cube.h
