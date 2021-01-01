#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

class Board : public QWidget
{
    Q_OBJECT
public:
    enum Team {
        Black,
        White
    };

    explicit Board(QWidget *parent = nullptr);


signals:

};

#endif // BOARD_H
