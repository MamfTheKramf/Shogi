#include "TestSilverGeneral.h"
#include "SilverGeneral.h"
#include "functions.h"


void TestSilverGeneral::testGetReachableFieldsNormal()
{
    SilverGeneral bSG(4, 4, Board::Team::Black);
    auto actual = bSG.getReachableFields();
    std::vector<Position> expected = {{3, 3}, {4, 3}, {5, 3},
                                      {3, 5}, {5, 5}};
    QVERIFY(containSameElements(actual, expected));

    SilverGeneral wSG(4, 4, Board::Team::White);
    actual = wSG.getReachableFields();
    expected = {{3, 3}, {5, 3},
                {3, 5}, {4, 5}, {5, 5}};
    QVERIFY(containSameElements(actual, expected));

    // check if trimming works
    bSG.setPos(0, 8);
    actual = bSG.getReachableFields();
    expected = {{0, 7}, {1, 7}};
    QVERIFY(containSameElements(actual, expected));

    wSG.setPos(5, 8);
    actual = wSG.getReachableFields();
    expected = {{4, 7}, {6, 7}};
    QVERIFY(containSameElements(actual, expected));
}
