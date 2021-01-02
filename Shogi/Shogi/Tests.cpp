#include "TestGeneral.h"
#include "TestPawn.h"
#include "TestLance.h"
#include "TestKnight.h"
#include "TestSilverGeneral.h"
#include "TestGoldGeneral.h"

void runTests() {
    TestGeneral tGeneral;
    TestPawn tPawn;
    TestLance tLance;
    TestKnight tKnight;
    TestSilverGeneral tSG;
    TestGoldGeneral tGG;


    QTest::qExec(&tGeneral);
    QTest::qExec(&tPawn);
    QTest::qExec(&tLance);
    QTest::qExec(&tKnight);
    QTest::qExec(&tSG);
    QTest::qExec(&tGG);
}
