#ifndef TESTKING_H
#define TESTKING_H

#include <QTest>

class TestKing : public QObject
{
    Q_OBJECT

private slots:
    void testGetReachableFields();

};

#endif // TESTKING_H
