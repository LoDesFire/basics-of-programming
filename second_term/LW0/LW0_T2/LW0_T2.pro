QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circle.cpp \
    hexagon.cpp \
    main.cpp \
    mainwindow.cpp \
    myfigure.cpp \
    rectangle.cpp \
    rhombus.cpp \
    shape.cpp \
    square.cpp \
    star.cpp \
    triangle.cpp

HEADERS += \
    circle.h \
    hexagon.h \
    mainwindow.h \
    myfigure.h \
    rectangle.h \
    rhombus.h \
    shape.h \
    square.h \
    star.h \
    triangle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
