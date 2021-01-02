#include "TestRook.h"
#include "Rook.h"
#include "functions.h"

void TestRook::testGetReachableFields()
{
    Rook bRook(4, 4, Board::Team::Black);
    auto actual = bRook.getReachableFields();
    std::vector<Position> expected = {{4, 3}, {4, 2}, {4, 1}, {4, 0},
                                      {4, 5}, {4, 6}, {4, 7}, {4, 8},
                                      {3, 4}, {2, 4}, {1, 4}, {0, 4},
                                      {5, 4}, {6, 4}, {7, 4}, {8, 4}};
    QVERIFY(containSameElements(actual, expected));

    Rook wRook(4, 4, Board::Team::White);
    actual = wRook.getReachableFields();
    QVERIFY(containSameElements(actual, expected));

    bRook.setPos(3, 2);
    actual = bRook.getReachableFields();
    expected = {{3, 1}, {3, 0},
                {2, 2}, {1, 2}, {0, 2},
                {4, 2}, {5, 2}, {6, 2}, {7, 2}, {8, 2},
                {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7}, {3, 8}};
    QVERIFY(containSameElements(actual, expected));

    wRook.setPos(8, 8);
    actual = wRook.getReachableFields();
    expected = {{7, 8}, {6, 8}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8},
                {8, 7}, {8, 6}, {8, 5}, {8, 4}, {8, 3}, {8, 2}, {8, 1}, {8, 0}};
    QVERIFY(containSameElements(actual, expected));
}

void TestRook::testGetReachableFieldsPromoted()
{
    Rook bRook(4, 4, Board::Team::Black, true);
    auto actual = bRook.getReachableFields();
    std::vector<Position> expected = {{4, 3}, {4, 2}, {4, 1}, {4, 0},
                                        {4, 5}, {4, 6}, {4, 7}, {4, 8},
                                        {3, 4}, {2, 4}, {1, 4}, {0, 4},
                                        {5, 4}, {6, 4}, {7, 4}, {8, 4},
                                      {3, 3}, {5, 5}, {5, 3}, {3, 5}};
    QVERIFY(containSameElements(actual, expected));

    Rook wRook(4, 4, Board::Team::White, true);
    actual = wRook.getReachableFields();
    QVERIFY(containSameElements(actual, expected));

    bRook.setPos(1, 0);
    actual = bRook.getReachableFields();
    expected = {{0, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0},
                {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8},
                {0, 1}, {2, 1}};
    QVERIFY(containSameElements(actual, expected));

    wRook.setPos(8, 8);
    actual = wRook.getReachableFields();
    expected = {{8, 7}, {8, 6}, {8, 5}, {8, 4}, {8, 3}, {8, 2}, {8, 1}, {8, 0},
                {7, 8}, {6, 8}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8},
                {7, 7}};
    QVERIFY(containSameElements(actual, expected));
}
