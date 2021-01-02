#ifndef TESTBISHOP_H
#define TESTBISHOP_H

#include <QTest>

class TestBishop : public QObject
{
    Q_OBJECT

private slots:
    void testGetReachableFields();

};

#endif // TESTBISHOP_H
