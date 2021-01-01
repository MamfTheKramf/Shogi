#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

class Board : public QWidget
{
    Q_OBJECT
public:
    //black moves up; white moves down
    enum Team {
        Black,
        White
    };

    explicit Board(QWidget *parent = nullptr);



};

#endif // BOARD_H
