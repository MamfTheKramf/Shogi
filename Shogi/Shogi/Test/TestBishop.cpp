#include "TestBishop.h"
#include "Bishop.h"
#include "functions.h"

void TestBishop::testGetReachableFields()
{
    Bishop bBishop(4, 4, Board::Team::Black);
    auto actual = bBishop.getReachableFields();
    std::vector<Position> expected = {{0, 0}, {1, 1}, {2, 2}, {3, 3},
                                      {5, 5}, {6, 6}, {7, 7}, {8, 8},
                                      {8, 0}, {7, 1}, {6, 2}, {5, 3},
                                      {0, 8}, {1, 7}, {2, 6}, {3, 5}};
    QVERIFY(containSameElements(actual, expected));

    Bishop wBishop(4, 4, Board::Team::White);
    actual = wBishop.getReachableFields();
    QVERIFY(containSameElements(actual, expected));

    bBishop.setPos(0, 0);
    actual = bBishop.getReachableFields();
    expected = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}};

    wBishop.setPos(6, 8);actual = wBishop.getReachableFields();
    expected = {{7, 7}, {8, 6},
                {5, 7}, {4, 6}, {3, 5}, {2, 4}, {1, 3}, {0, 2}};
    QVERIFY(containSameElements(actual, expected));
}

void TestBishop::testGetReachableFieldsPromoted()
{
    Bishop bBishop(4, 4, Board::Team::Black, true);
    auto actual = bBishop.getReachableFields();
    std::vector<Position> expected = {{0, 0}, {1, 1}, {2, 2}, {3, 3},
                                      {5, 5}, {6, 6}, {7, 7}, {8, 8},
                                      {8, 0}, {7, 1}, {6, 2}, {5, 3},
                                      {0, 8}, {1, 7}, {2, 6}, {3, 5},
                                      {4, 3}, {5, 4}, {4, 5}, {3, 4}};
    QVERIFY(containSameElements(actual, expected));

    Bishop wBishop(4, 4, Board::Team::White, true);
    actual = wBishop.getReachableFields();
    QVERIFY(containSameElements(actual, expected));

    bBishop.setPos(6, 8);
    actual = bBishop.getReachableFields();
    expected = {{7, 7}, {8, 6}, {5, 8}, {7, 8}, {6, 7},
                {5, 7}, {4, 6}, {3, 5}, {2, 4}, {1, 3}, {0, 2}};
    QVERIFY(containSameElements(actual, expected));

    wBishop.setPos(8, 0);
    actual = wBishop.getReachableFields();
    expected = {{7, 1}, {6, 2}, {5, 3}, {4, 4}, {3, 5}, {2, 6}, {1, 7}, {0, 8},
                {7, 0}, {8, 1}};
    QVERIFY(containSameElements(actual, expected));
}
