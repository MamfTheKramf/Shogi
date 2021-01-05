#ifndef GOLDGENERAL_H
#define GOLDGENERAL_H

#include "Piece.h"

class GoldGeneral : public Piece
{
public:
    GoldGeneral(Board::Team team);

    GoldGeneral(int x, int y, Board::Team team);

    GoldGeneral(const Position& p, Board::Team team);

    GoldGeneral(Board* board, int x, int y, Board::Team team, bool promoted = false);

    GoldGeneral(Board* board, const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields() const override;

    QString getPic() const override;

    static const QString pic;
};

#endif // GOLDGENERAL_H
