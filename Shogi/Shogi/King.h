#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:
    King(Board::Team team);

    King(int x, int y, Board::Team team);

    King(const Position& p, Board::Team team);

    std::vector<Position> getReachableFields() const override;
};

#endif // KING_H
