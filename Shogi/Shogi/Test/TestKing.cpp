#include "TestKing.h"
#include "King.h"
#include "functions.h"


void TestKing::testGetReachableFields()
{
    King bKing(4, 4, Board::Team::Black);
    auto actual = bKing.getReachableFields();
    std::vector<Position> expected = {{3, 3}, {4, 3}, {5, 3},
                                      {3, 4}, {5, 4},
                                      {3, 5}, {4, 5}, {5, 5}};
    QVERIFY(containSameElements(actual, expected));

    King wKing(4, 4, Board::Team::White);
    actual = wKing.getReachableFields();
    QVERIFY(containSameElements(actual, expected));

    bKing.setPos(0, 8);
    actual = bKing.getReachableFields();
    expected = {{0, 7}, {1, 7},
                {1, 8}};
    QVERIFY(containSameElements(actual, expected));

    wKing.setPos(5, 0);
    actual = wKing.getReachableFields();
    expected = {{4, 0}, {6, 0},
                {4, 1}, {5, 1}, {6, 1}};
    QVERIFY(containSameElements(actual, expected));
}
