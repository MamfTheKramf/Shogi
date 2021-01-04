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

    QString getPic() const override;

    static const QString pic;
};

#endif // GOLDGENERAL_H
