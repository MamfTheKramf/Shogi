#include "TestBoard.h"
#include "Board.h"

void TestBoard::testIsOccupied()
{
    Board b(nullptr);
    QCOMPARE(b.isOccupied({4, 4}), -1);

    QCOMPARE(b.isOccupied({0, 0}), Board::Team::White);

    QCOMPARE(b.isOccupied({4, 8}), Board::Team::Black);
}

void TestBoard::testIsSafe()
{
    Board b(nullptr);
    QCOMPARE(b.isSafe({0, 1}, Board::Team::White), false);

    QCOMPARE(b.isSafe({0, 1}, Board::Team::Black), true);

    QCOMPARE(b.isSafe({4, 4}, Board::Team::White), true);

    QCOMPARE(b.isSafe({4, 4}, Board::Team::Black), true);

    QCOMPARE(b.isSafe({7, 3}, Board::Team::White), false);

    QCOMPARE(b.isSafe({2, 5}, Board::Team::Black), false);

    QCOMPARE(b.isSafe({4, 1}, Board::Team::White), false);

    QCOMPARE(b.isSafe({4, 7}, Board::Team::Black), false);
}
