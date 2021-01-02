#include "TestGeneral.h"
#include "TestPawn.h"
#include "TestLance.h"
#include "TestKnight.h"

void runTests() {
    TestGeneral tGeneral;
    TestPawn tPawn;
    TestLance tLance;
    TestKnight tKnight;


    QTest::qExec(&tGeneral);
    QTest::qExec(&tPawn);
    QTest::qExec(&tLance);
    QTest::qExec(&tKnight);
}
