#include "TestPawn.h"
#include "Pawn.h"

void TestPawn::testGetPos()
{
    Pawn p1(1, 1, Board::Team::Black);
    auto actual = p1.getPos();
    auto expected = Position(1, 1);
    QCOMPARE(actual, expected);

    Pawn p2({0, 0}, Board::Team::White);
    actual = p2.getPos();
    expected = Position(0, 0);
    QCOMPARE(actual, expected);
}

void TestPawn::testGetTeam()
{
    Pawn p1(Board::Team::Black);
    QCOMPARE(p1.getTeam(), Board::Team::Black);

    Pawn p2(Board::Team::White);
    QCOMPARE(p2.getTeam(), Board::Team::White);

    Pawn p3(1, 5, Board::Team::Black);
    QCOMPARE(p3.getTeam(), Board::Team::Black);
}

void TestPawn::testIsPromoted()
{
    Pawn p1(Board::Team::Black);
    QCOMPARE(p1.isPromoted(), false);

    Pawn p2(8, 8, Board::Team::White);
    QCOMPARE(p2.isPromoted(), false);
}

void TestPawn::testSetPos()
{
    Pawn p1(3, 2, Board::Team::Black);
    p1.setPos(5, 5);
    QCOMPARE(p1.getPos(), Position(5, 5));

    p1.setPos(Position(8, 2));
    QCOMPARE(p1.getPos(), Position(8, 2));

    p1.setPos(-1, -1);
    QCOMPARE(p1.getPos(), Position(-1, -1));
}

void TestPawn::testPromote()
{
    Pawn p1(Board::Team::Black);
    p1.promote();
    QCOMPARE(p1.isPromoted(), true);

    //once promoted pieces stay promoted
    p1.promote();
    QCOMPARE(p1.isPromoted(), true);
}

void TestPawn::testReachableFieldsNormal()
{
    //black case
    Pawn blackPawn(4, 4, Board::Team::Black);
    auto actual = blackPawn.getReachableFields();
    auto expected = std::vector<Position>();
    expected.push_back({4, 3});
    QCOMPARE(actual, expected);

    //white case
    Pawn whitePawn(8, 7, Board::Team::White);
    actual = whitePawn.getReachableFields();
    expected[0] = Position(8, 8);
    QCOMPARE(actual, expected);

}

void TestPawn::testReachableFieldsOutOfBounds()
{
    auto expected = std::vector<Position>();
    //Black case
    Pawn blackPawn(4, 0, Board::Team::Black);
    auto actual = blackPawn.getReachableFields();
    QCOMPARE(actual, expected);

    //White case
    Pawn whitePawn(7, 8, Board::Team::White);
    actual = whitePawn.getReachableFields();
    QCOMPARE(actual, expected);
}
