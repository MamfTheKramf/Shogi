#ifndef GOLDGENERAL_H
#define GOLDGENERAL_H

#include "Piece.h"

class GoldGeneral : public Piece
{
public:
    GoldGeneral(Board::Team team);

    GoldGeneral(int x, int y, Board::Team team);

    GoldGeneral(const Position& p, Board::Team team);

    std::vector<Position> getReachableFields() const override;
};

#endif // GOLDGENERAL_H
