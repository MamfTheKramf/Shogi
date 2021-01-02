#ifndef TESTKNIGHT_H
#define TESTKNIGHT_H

#include <QTest>

class TestKnight : public QObject
{
    Q_OBJECT
private slots:
    void testGetReachableFieldsNormal();
    //promoted check is skipped since it is implemented the same why as it is in pawn and lance
};

#endif // TESTKNIGHT_H
