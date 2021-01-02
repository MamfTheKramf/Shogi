#ifndef TESTPAWN_H
#define TESTPAWN_H

#include <QTest>

class TestPawn : public QObject
{
    Q_OBJECT
private slots:


    void testGetPos();
    void testGetTeam();
    void testIsPromoted();
    void testSetPos();
    void testPromote();
    void testReachableFieldsNormal();
    void testReachableFieldsOutOfBounds();
    void testGetReachableFieldsPromoted();
};

#endif // TESTPAWN_H
