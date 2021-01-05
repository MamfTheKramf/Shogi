#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{

public:
    Bishop(Board::Team team);

    Bishop(int x, int y, Board::Team team, bool promoted = false);

    Bishop(const Position& p, Board::Team team, bool promoted = false);

    Bishop(Board* board, int x, int y, Board::Team team, bool promoted = false);

    Bishop(Board* board, const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields() const override;

    QString getPic() const override;

    static const QString pic;
};

#endif // BISHOP_H
