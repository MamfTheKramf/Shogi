#include "TestBoard.h"
#include "Board.h"

void TestBoard::testIsOccupied()
{
    Board b(nullptr);
    QCOMPARE(b.isOccupied({4, 4}), -1);

    QCOMPARE(b.isOccupied({0, 0}), Board::Team::White);

    QCOMPARE(b.isOccupied({4, 8}), Board::Team::Black);
}
