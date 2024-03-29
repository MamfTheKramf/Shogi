QT       += core gui
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += Test

SOURCES += \
    Bishop.cpp \
    Board.cpp \
    GoldGeneral.cpp \
    King.cpp \
    Knight.cpp \
    Lance.cpp \
    Pawn.cpp \
    Piece.cpp \
    Position.cpp \
    Rook.cpp \
    SilverGeneral.cpp \
    Test/TestBishop.cpp \
    Test/TestBoard.cpp \
    Test/TestGeneral.cpp \
    Test/TestGoldGeneral.cpp \
    Test/TestKing.cpp \
    Test/TestKnight.cpp \
    Test/TestLance.cpp \
    Test/TestPawn.cpp \
    Test/TestRook.cpp \
    Test/TestSilverGeneral.cpp \
    Test/Tests.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Bishop.h \
    Board.h \
    GoldGeneral.h \
    King.h \
    Knight.h \
    Lance.h \
    MainWindow.h \
    Pawn.h \
    Piece.h \
    Position.h \
    Rook.h \
    SilverGeneral.h \
    Test/TestBishop.h \
    Test/TestBoard.h \
    Test/TestGeneral.h \
    Test/TestGoldGeneral.h \
    Test/TestKing.h \
    Test/TestKnight.h \
    Test/TestLance.h \
    Test/TestPawn.h \
    Test/TestRook.h \
    Test/TestSilverGeneral.h \
    functions.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
