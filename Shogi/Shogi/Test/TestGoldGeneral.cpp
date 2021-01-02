#include "TestGoldGeneral.h"
#include "GoldGeneral.h"
#include "functions.h"

void TestGoldGeneral::testPromote()
{
    GoldGeneral GG(4, 4, Board::Team::Black);
    GG.promote(); //goldGenerals shouldn't be promotable, therefor nothing should happen
    QVERIFY(!GG.isPromoted());
}

void TestGoldGeneral::testGetReachableFields()
{
    GoldGeneral bGG(4, 4, Board::Team::Black);
    auto actual = bGG.getReachableFields();
    std::vector<Position> expected = {{3, 3}, {4, 3}, {5, 3},
                                      {3, 4}, {5, 4},
                                      {4, 5}};
    QVERIFY(containSameElements(actual, expected));

    GoldGeneral wGG(4, 4, Board::Team::White);
    actual = wGG.getReachableFields();
    expected = {{4, 3},
                {3, 4}, {5, 4},
                {3, 5}, {4, 5}, {5, 5}};
    QVERIFY(containSameElements(actual, expected));

    bGG.setPos(3, 0);
    actual = bGG.getReachableFields();
    expected = {{2, 0}, {4, 0},
                {3, 1}};
    QVERIFY(containSameElements(actual, expected));

    wGG.setPos(8, 8);
    actual = wGG.getReachableFields();
    expected = {{8, 7},
                {7, 8}};
    QVERIFY(containSameElements(actual, expected));
}
