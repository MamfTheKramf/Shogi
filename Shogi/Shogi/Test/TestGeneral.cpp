#include "TestGeneral.h"
#include "functions.h"

void TestGeneral::testContainSameElements()
{
    std::vector<int> a = {1, 2, 3, 4, 5, 6};
    std::vector<int> b = {1, 2, 3, 4, 5, 6};
    QVERIFY(containSameElements(a, b));

    a = {};
    b = {};
    QVERIFY(containSameElements(a, b));

    b = {2, 10, 6, -3};
    QVERIFY(!containSameElements(a, b));

    a = {10, 6, 2, -3};
    QVERIFY(containSameElements(a, b));

    a = {10, 10, 6, -3};
    QVERIFY(!containSameElements(a, b));
}
