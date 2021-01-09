#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <QString>

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

protected:
    Position _pos;
    bool _isPromoted;
    const bool _isPromotable;
    const Piece::Type _type;
    Board::Team _team;
    Board* _board;

public:

    Piece(Position p, bool promoted, bool promotable, Piece::Type ty, Board::Team team, Board* board = nullptr);

    Position getPos() const;
    void setPos(int x, int y);
    void setPos(const Position& p);
    bool isPromoted() const;
    Piece::Type getType() const;
    Board::Team getTeam() const;

    void promote();

    virtual std::vector<Position> getReachableFields() const = 0;
    virtual QString getPic() const = 0;


protected:
    // made this method part of the base class since so many pieces get this movement when promoted
    std::vector<Position> getGoldGeneralReachableFields() const;
    void changeTeam();
};

#endif // PIECE_H
