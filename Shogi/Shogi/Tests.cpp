#include "TestGeneral.h"
#include "TestPawn.h"
#include "TestLance.h"

void runTests() {
    TestGeneral tGeneral;
    QTest::qExec(&tGeneral);

    TestPawn tPawn;
    QTest::qExec(&tPawn);

    TestLance tLance;
    QTest::qExec(&tLance);
}
