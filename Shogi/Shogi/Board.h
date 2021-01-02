#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <array>
#include <vector>
#include <memory>

#include "Position.h"

class Piece;

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

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

    void initBoard();

private:
    // 2D-Array representing the board
    using Data = std::array<std::array<std::shared_ptr<Piece>, 9>, 9>;
    Data _data;

    int _fieldWidth = 20;

    // stores how many of each pieces are catured by each player
    std::array<int, 8> _capturedBlack;
    std::array<int, 8> _capturedWhite;

    // stores the pieces ON the board belonging to each player
    std::vector<std::shared_ptr<Piece>> _boardBlack;
    std::vector<std::shared_ptr<Piece>> _boardWhite;

    Board::Team _activePlayer;

    Position _selectedField;
    std::vector<Position> _highlightedFields;

};

#endif // BOARD_H
