#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include "Board.h"
#include "Position.h"

class Piece
{
public:
    enum Type {
        Pawn,
        Lance,
        Knight,
        SilverGeneral,
        GoldGeneral,
        Bishop,
        Rook,
        King
    };

private:
    Position _pos;
    bool _isPromoted;
    const bool _isPromotable;
    const Piece::Type _type;
    Board::Team _team;

public:

    Piece(Position p, bool promoted, bool promotable, Piece::Type ty, Board::Team team);

    Position getPos() const;
    void setPos(int x, int y);
    void setPos(const Position& p);
    bool isPromoted() const;
    Piece::Type getType() const;
    Board::Team getTeam() const;

    void promote();

    virtual std::vector<Position> getReachableFields() const = 0;
};

#endif // PIECE_H
