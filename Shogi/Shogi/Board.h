#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <array>
#include <vector>
#include <memory>
#include <QString>

#include "Position.h"
class Piece;

class QPainter;

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

    int isOccupied(Position p);

    bool isSafe(Position p, Board::Team opponent);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

    void initBoard();
    void drawPiece(QPainter* painter, float x, float y, float w, float h, Board::Team team, const QString& url) const;
    Position getClickedField(int x, int y) const;
    void updateWinTitle();
    // returns true when King was killed and the game should end
    bool move(Position from, Position to);
    void changePlayer();
    std::vector<Position> getDropFields(int type);
    bool isCheckmate();
    void endGame();
    void reset();

private:
    // 2D-Array representing the board
    using Data = std::array<std::array<std::shared_ptr<Piece>, 9>, 9>;
    Data _data;

    int _offset = 5;
    int _fieldWidth = 60;

    // stores how many of each pieces are catured by each player
    std::array<int, 7> _numbersBlack;
    std::array<int, 7> _numbersWhite;

    // stores the pieces ON the board belonging to each player
    std::list<std::shared_ptr<Piece>> _boardBlack;
    std::list<std::shared_ptr<Piece>> _boardWhite;

    Board::Team _activePlayer;

    Position _selectedField;
    std::vector<Position> _highlightedFields;

    QPixmap _background;

};

#endif // BOARD_H
