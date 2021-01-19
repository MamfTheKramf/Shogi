#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(Board::Team team);

    Knight(int x, int y, Board::Team team, bool promoted = false);

    Knight(const Position& p, Board::Team team, bool promoted = false);

    Knight(Board* board, int x, int y, Board::Team team, bool promoted = false);

    Knight(Board* board, const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields(bool includeFriendlyFields = false) const override;

    QString getPic() const override;

    static const QString pic;
    static const QString pic_promoted;
};

#endif // KNIGHT_H
