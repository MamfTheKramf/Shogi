#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(Board::Team team);

    Bishop(int x, int y, Board::Team team, bool promoted = false);

    Bishop(const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields() const override;
};

#endif // BISHOP_H
