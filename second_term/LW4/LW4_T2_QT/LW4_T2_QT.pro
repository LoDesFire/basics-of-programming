QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h


FORMS += \
    mainwindow.ui

DEFINES += STRING_LIBRARY


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L"/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/build-String-Desktop_Qt_5_15_2_clang_64bit-Debug/" -lString.1.0.0

#INCLUDEPATH += "/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW4/LW4_T2_QT/Headers"
#DEPENDPATH += "/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW4/LW4_T2/Headers"
