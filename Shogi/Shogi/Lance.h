#ifndef LANCE_H
#define LANCE_H

#include "Piece.h"

class Lance : public Piece
{
public:
    Lance(Board::Team team);

    Lance(int x, int y, Board::Team team, bool promoted = false);

    Lance(const Position& p, Board::Team team, bool promoted = false);

    Lance(Board* board, int x, int y, Board::Team team, bool promoted = false);

    Lance(Board* board, const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields(bool includeFriendlyFields = false) const override;

    QString getPic() const override;

    static const QString pic;
    static const QString pic_promoted;
};

#endif // LANCE_H
