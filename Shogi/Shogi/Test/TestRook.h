#ifndef TESTROOK_H
#define TESTROOK_H

#include <QTest>

class TestRook : public QObject
{
    Q_OBJECT

private slots:
    void testGetReachableFields();
    void testGetReachableFieldsPromoted();
};

#endif // TESTROOK_H
