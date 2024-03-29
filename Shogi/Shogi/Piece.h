#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <QString>
#include <QDebug>

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

    ~Piece();

    Position getPos() const;
    void setPos(int x, int y);
    void setPos(const Position& p);
    bool isPromoted() const;
    bool isPromotable() const;
    Piece::Type getType() const;
    Board::Team getTeam() const;

    void promote();

    // if includeFriendlyFields is true the fields that would be taken out because there are friendly pieces will be included
    virtual std::vector<Position> getReachableFields(bool includeFiendlyFields = false) const = 0;
    virtual QString getPic() const = 0;

protected:
    // made this method part of the base class since so many pieces get this movement when promoted
    std::vector<Position> getGoldGeneralReachableFields(bool includeFriendlyFields = false) const;
    void changeTeam();
};

#endif // PIECE_H
