#ifndef PAWN_H
#define PAWN_H

#include <vector>

#include "Piece.h"
#include "Position.h"
#include "Board.h"

class Pawn : public Piece
{
public:
    Pawn(Board::Team team);

    Pawn(int x, int y, Board::Team team, bool promoted = false);

    Pawn(const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields() const override;
};

#endif // PAWN_H
