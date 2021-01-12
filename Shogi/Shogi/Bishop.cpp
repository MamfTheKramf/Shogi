#include "Bishop.h"

const QString Bishop::pic(":/assets/Assets/bishop.png");
const QString Bishop::pic_promoted(":/assets/Assets/bishop_promoted.png");

Bishop::Bishop(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::Bishop, team)
{}

Bishop::Bishop(int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Bishop, team)
{}

Bishop::Bishop(const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Bishop, team)
{}

Bishop::Bishop(Board *board, int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Bishop, team, board)
{}

Bishop::Bishop(Board *board, const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Bishop, team, board)
{}

std::vector<Position> Bishop::getReachableFields() const
{
    std::vector<Position> ret;

    // up-left direction
    int offset = 1;
    while (_pos.x - offset >= 0 && _pos.y - offset >= 0) {
        Position p(_pos.x - offset, _pos.y - offset);
        int res = _board ? _board->isOccupied(p) : -1;
        // only add the position when there isn't a teammate on the field
        if (res != _team) {
            ret.push_back(p);
        }
        // stop moving in this direction when the field in't empty
        if (res != -1) {
            break;
        }
        offset++;
    }
    // up-right direction
    offset = 1;
    while (_pos.x + offset < 9 && _pos.y - offset >= 0) {
        Position p({_pos.x + offset, _pos.y - offset});
        int res = _board ? _board->isOccupied(p) : -1;
        // only add the position when there isn't a teammate on the field
        if (res != _team) {
            ret.push_back(p);
        }
        // stop moving in this direction when the field in't empty
        if (res != -1) {
            break;
        }
        offset++;
    }
    // down-left direction
    offset = 1;
    while (_pos.x - offset >= 0 && _pos.y + offset < 9) {
        Position p({_pos.x - offset, _pos.y + offset});
        int res = _board ? _board->isOccupied(p) : -1;
        // only add the position when there isn't a teammate on the field
        if (res != _team) {
            ret.push_back(p);
        }
        // stop moving in this direction when the field in't empty
        if (res != -1) {
            break;
        }
        offset++;
    }
    // down-right direction
    offset = 1;
    while (_pos.x + offset < 9 && _pos.y + offset < 9) {
        Position p({_pos.x + offset, _pos.y + offset});
        int res = _board ? _board->isOccupied(p) : -1;
        // only add the position when there isn't a teammate on the field
        if (res != _team) {
            ret.push_back(p);
        }
        // stop moving in this direction when the field in't empty
        if (res != -1) {
            break;
        }
        offset++;
    }

    // pomoted extra
    if (_isPromoted) {
        if (_pos.x - 1 >= 0) {
            Position p({_pos.x - 1, _pos.y});
            int res = _board ? _board->isOccupied(p) : -1;
            if (res != _team) {
                ret.push_back(p);
            }
        }
        if (_pos.x + 1 < 9) {
            Position p({_pos.x + 1, _pos.y});
            int res = _board ? _board->isOccupied(p) : -1;
            if (res != _team) {
                ret.push_back(p);
            }
        }
        if (_pos.y - 1 >= 0) {
            Position p({_pos.x, _pos.y - 1});
            int res = _board ? _board->isOccupied(p) : -1;
            if (res != _team) {
                ret.push_back(p);
            }
        }
        if (_pos.y + 1 < 9) {
            Position p({_pos.x, _pos.y + 1});
            int res = _board ? _board->isOccupied(p) : -1;
            if (res != _team) {
                ret.push_back(p);
            }
        }
    }

    return ret;
}

QString Bishop::getPic() const
{
    if (!_isPromoted)
        return pic;
    return pic_promoted;
}
