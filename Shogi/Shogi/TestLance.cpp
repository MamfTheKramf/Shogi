#include "TestLance.h"
#include "Lance.h"
#include "functions.h"

void TestLance::testGetReachableFieldsNormal() {
    // this lance can't move anymore
    Lance l1(4, 0, Board::Team::Black);
    auto actual = l1.getReachableFields();
    auto expected = std::vector<Position>();
    QCOMPARE(actual, expected);

    Lance l2(2, 8, Board::Team::White);
    actual = l2.getReachableFields();
    QCOMPARE(actual, expected);

    Lance l3(4, 4, Board::Team::Black);
    actual = l3.getReachableFields();
    expected = {Position(4, 0), Position(4, 1), Position(4, 2), Position(4, 3)};
    QCOMPARE(actual, expected);

    Lance l4(0, 0, Board::Team::White);
    actual = l4.getReachableFields();
    expected = {Position(0, 8),
               Position(0, 7),
               Position(0, 6),
               Position(0, 5),
               Position(0, 4),
               Position(0, 3),
               Position(0, 2),
               Position(0, 1)};
    QCOMPARE(actual, expected);
}

void TestLance::testGetReachableFieldsPromoted()
{
    Lance blackLance(4, 4, Board::Team::Black, true);
    auto actual = blackLance.getReachableFields();
    std::vector<Position> expected = {{4, 5},
                                      {3, 3}, {4, 3}, {5, 3},
                                      {3, 4}, {5, 4}};
    QVERIFY(containSameElements(actual, expected));

    Lance whiteLance(4, 4, Board::Team::White, true);
    actual = whiteLance.getReachableFields();
    expected = {{4, 3},
                {3, 4}, {5, 4},
                {3, 5}, {4, 5}, {5, 5}};
    QVERIFY(containSameElements(actual, expected));
}
