#ifndef SILVERGENERAL_H
#define SILVERGENERAL_H

#include "Piece.h"

class SilverGeneral : public Piece
{
public:
    SilverGeneral(Board::Team team);

    SilverGeneral(int x, int y, Board::Team team, bool promoted = false);

    SilverGeneral(const Position& p, Board::Team team, bool promoted = false);

    SilverGeneral(Board* board, int x, int y, Board::Team team, bool promoted = false);

    SilverGeneral(Board* board, const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields() const override;

    QString getPic() const override;

    static const QString pic;
    static const QString pic_promoted;
};

#endif // SILVERGENERAL_H
