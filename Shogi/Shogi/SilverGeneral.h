#ifndef SILVERGENERAL_H
#define SILVERGENERAL_H

#include "Piece.h"

class SilverGeneral : public Piece
{
public:
    SilverGeneral(Board::Team team);

    SilverGeneral(int x, int y, Board::Team team, bool promoted = false);

    SilverGeneral(const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields() const override;
};

#endif // SILVERGENERAL_H
