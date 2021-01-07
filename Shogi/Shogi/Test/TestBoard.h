#ifndef TESTBOARD_H
#define TESTBOARD_H

#include <QTest>

class TestBoard : public QObject
{
    Q_OBJECT

private slots:
    void testIsOccupied();
    void testIsSafe();
};

#endif // TESTBOARD_H
