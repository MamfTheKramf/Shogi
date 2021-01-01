#include "TestPiece.h"

void runTests() {
    TestPiece* tp = new TestPiece();
    QTest::qExec(tp);
}
