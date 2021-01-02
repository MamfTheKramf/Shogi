#ifndef TESTGENERAL_H
#define TESTGENERAL_H

#include <QTest>

class TestGeneral : public QObject
{
    Q_OBJECT
private slots:
    void testContainSameElements();

};

#endif // TESTGENERAL_H
