#include "TestKnight.h"
#include "Knight.h"
#include "functions.h"

void TestKnight::testGetReachableFieldsNormal()
{
    Knight bKnight(4, 4, Board::Team::Black);
    auto actual = bKnight.getReachableFields();
    std::vector<Position> expected = {{3, 2}, {5, 2}};
    QVERIFY(containSameElements(actual, expected));

    Knight wKnight(4, 4, Board::Team::White);
    actual = wKnight.getReachableFields();
    expected = {{3, 6}, {5, 6}};
    QVERIFY(containSameElements(actual, expected));

    bKnight.setPos(7, 1);
    actual = bKnight.getReachableFields();
    expected = {};
    QVERIFY(containSameElements(actual, expected));

    wKnight.setPos(8, 5);
    actual = wKnight.getReachableFields();
    expected = {{7, 7}};
    QVERIFY(containSameElements(actual, expected));
}
