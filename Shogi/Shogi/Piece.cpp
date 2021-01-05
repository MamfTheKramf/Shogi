#include "Piece.h"

Piece::Piece(Position p, bool promoted, bool promotable, Piece::Type ty, Board::Team team, Board* board):
    _pos(p),
    _isPromoted(promoted),
    _isPromotable(promotable),
    _type(ty),
    _team(team),
    _board(board)
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
    // that why a piece will only promote if _isPromotable is true
    _isPromoted = _isPromotable;
}

std::vector<Position> Piece::getGoldGeneralReachableFields() const
{
    std::vector<Position> ret;
    for (int x = _pos.x-1; x <= _pos.x+1; x++) {
        if (x < 0 || x >= 9) //out of bound
            continue;

        for (int y = _pos.y-1; y <= _pos.y+1; y++) {
            if ((y < 0 || y >= 9) //out of bound
                || (_team == Board::Team::Black && y == _pos.y + 1 && x != _pos.x) // diagonal behind BLACK
                || (_team == Board::Team::White && y == _pos.y - 1 && x != _pos.x) // diagonal behind WHITE
                || (x == _pos.x && y == _pos.y)) // current Pos
            {
                continue;
            }

            ret.push_back({x, y});
        }
    }
    return ret;
}
