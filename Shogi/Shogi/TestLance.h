#ifndef TESTLANCE_H
#define TESTLANCE_H

#include <QTest>

class TestLance : public QObject
{
    Q_OBJECT

private slots:
    //the tests for position and promoting and all can be skipped
    // since they were done for the pawn and those methods are inherited

    void testGetReachableFieldsNormal();
    void testGetReachableFieldsPromoted();

};

#endif // TESTLANCE_H
