#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
private:
    QString _blackPic;
    QString _whitePic;

public:
    King(Board::Team team);

    King(int x, int y, Board::Team team);

    King(const Position& p, Board::Team team);

    King(Board* board, int x, int y, Board::Team team, bool promoted = false);

    King(Board* board, const Position& p, Board::Team team, bool promoted = false);

    std::vector<Position> getReachableFields() const override;
    QString getPic() const override;

    static const QString blackPic;
    static const QString whitePic;
};

#endif // KING_H
