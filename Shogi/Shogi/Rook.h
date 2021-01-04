#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(Board::Team team);

    Rook(int x, int y, Board::Team team, bool promoted = false);

    Rook(const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields() const override;

    QString getPic() const override;

    static const QString pic;
};

#endif // ROOK_H
