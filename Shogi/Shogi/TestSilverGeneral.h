#ifndef TESTSILVERGENERAL_H
#define TESTSILVERGENERAL_H

#include <QTest>

class TestSilverGeneral : public QObject
{
    Q_OBJECT

private slots:
    void testGetReachableFieldsNormal();
};

#endif // TESTSILVERGENERAL_H
