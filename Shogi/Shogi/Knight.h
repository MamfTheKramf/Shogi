#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(Board::Team team);

    Knight(int x, int y, Board::Team team, bool promoted = false);

    Knight(const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields() const override;
};

#endif // KNIGHT_H
