#ifndef LANCE_H
#define LANCE_H

#include "Piece.h"

class Lance : public Piece
{
public:
    Lance(Board::Team team);

    Lance(int x, int y, Board::Team team, bool promoted = false);

    Lance(const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields() const override;
};

#endif // LANCE_H
