#ifndef TESTGOLDGENERAL_H
#define TESTGOLDGENERAL_H

#include <QTest>

class TestGoldGeneral : public QObject
{
    Q_OBJECT

private slots:
    void testPromote();
    void testGetReachableFields();
};

#endif // TESTGOLDGENERAL_H
