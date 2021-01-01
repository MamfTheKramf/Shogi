QT       += core gui
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Board.cpp \
    Lance.cpp \
    Pawn.cpp \
    Piece.cpp \
    Position.cpp \
    TestGeneral.cpp \
    TestLance.cpp \
    TestPawn.cpp \
    Tests.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Board.h \
    Lance.h \
    MainWindow.h \
    Pawn.h \
    Piece.h \
    Position.h \
    TestGeneral.h \
    TestLance.h \
    TestPawn.h \
    functions.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
