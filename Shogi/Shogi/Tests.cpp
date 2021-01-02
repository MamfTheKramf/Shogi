#include "TestGeneral.h"
#include "TestPawn.h"
#include "TestLance.h"
#include "TestKnight.h"
#include "TestSilverGeneral.h"

void runTests() {
    TestGeneral tGeneral;
    TestPawn tPawn;
    TestLance tLance;
    TestKnight tKnight;
    TestSilverGeneral tSG;


    QTest::qExec(&tGeneral);
    QTest::qExec(&tPawn);
    QTest::qExec(&tLance);
    QTest::qExec(&tKnight);
    QTest::qExec(&tSG);
}
