#include "Piece.h"

Piece::Piece(Position p, bool promoted, bool promotable, Piece::Type ty, Board::Team team, Board* board):
    _pos(p),
    _isPromoted(promoted),
    _isPromotable(promotable),
    _type(ty),
    _team(team),
    _board(board)
{}

Piece::~Piece()
{
    qDebug() << "Piece removed";
}

Position Piece::getPos() const
{
    return _pos;
}

void Piece::setPos(int x, int y)
{
    setPos({x, y});
}

void Piece::setPos(const Position &p)
{
    // when set to such a position the piece is captured and shall change the team
    if (p.x < 0 && p.y < 0) {
        changeTeam();
        _isPromoted = false;
    }
    _pos = p;
}

bool Piece::isPromoted() const
{
    return _isPromoted;
}

bool Piece::isPromotable() const
{
    return _isPromotable;
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

std::vector<Position> Piece::getGoldGeneralReachableFields(bool includeFriendlyFields) const
{
    std::vector<Position> ret;
    for (int x = _pos.x-1; x <= _pos.x+1; x++) {
        if (x < 0 || x >= 9) //out of bound
            continue;

        for (int y = _pos.y-1; y <= _pos.y+1; y++) {
            if ((y < 0 || y >= 9) //out of bound
                || (_team == Board::Team::Black && y == _pos.y + 1 && x != _pos.x) // diagonal behind BLACK
                || (_team == Board::Team::White && y == _pos.y - 1 && x != _pos.x) // diagonal behind WHITE
                || (x == _pos.x && y == _pos.y) // current Pos
                || (_board && _board->isOccupied({x, y}) == _team && !includeFriendlyFields)) // Pos of teammate
            {
                continue;
            }

            ret.push_back({x, y});
        }
    }
    return ret;
}

void Piece::changeTeam()
{
    if (_team == Board::Team::Black) {
        _team = Board::Team::White;
    } else {
        _team = Board::Team::Black;
    }
}
