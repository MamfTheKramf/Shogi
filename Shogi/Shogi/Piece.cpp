#include "Piece.h"

Piece::Piece(Position p, bool promoted, bool promotable, Piece::Type ty, Board::Team team):
    _pos(p),
    _isPromoted(promoted),
    _isPromotable(promotable),
    _type(ty),
    _team(team)
{}

Position Piece::getPos() const
{
    return _pos;
}

void Piece::setPos(int x, int y)
{
    _pos = {x, y};
}

void Piece::setPos(const Position &p)
{
    _pos = p;
}

bool Piece::isPromoted() const
{
    return _isPromoted;
}

Piece::Type Piece::getType() const
{
    return _type;
}

Board::Team Piece::getTeam() const
{
    return _team;
}

void Piece::promote()
{
    _isPromoted = true;
}
