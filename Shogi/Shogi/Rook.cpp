#include "Rook.h"

const QString Rook::pic(":/assets/Assets/rook.png");
const QString Rook::pic_promoted(":/assets/Assets/rook_promoted.png");

Rook::Rook(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::Rook, team)
{}

Rook::Rook(int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Rook, team)
{}

Rook::Rook(const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Rook, team)
{}

Rook::Rook(Board *board, int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Rook, team, board)
{}

Rook::Rook(Board *board, const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Rook, team, board)
{}

std::vector<Position> Rook::getReachableFields() const {
    std::vector<Position> ret;

    // up
    for (int y = _pos.y - 1; y >= 0; y--) {
        int res = _board ? _board->isOccupied({_pos.x, y}) : -1;
        if (res != _team) {
            ret.push_back({_pos.x, y});
        }
        if (res != -1) {
            break;
        }
    }
    // down
    for (int y = _pos.y + 1; y < 9; y++) {
        int res = _board ? _board->isOccupied({_pos.x, y}) : -1;
        if (res != _team) {
            ret.push_back({_pos.x, y});
        }
        if (res != -1) {
            break;
        }
    }
    // left
    for (int x = _pos.x - 1; x >= 0; x --) {
        int res = _board ? _board->isOccupied({x, _pos.y}) : -1;
        if (res != _team) {
            ret.push_back({x, _pos.y});
        }
        if (res != -1) {
            break;
        }
    }
    // right
    for (int x = _pos.x + 1; x < 9; x ++) {
        int res = _board ? _board->isOccupied({x, _pos.y}) : -1;
        if (res != _team) {
            ret.push_back({x, _pos.y});
        }
        if (res != -1) {
            break;
        }
    }

    // diagonal fields for promoted rooks
    if (_isPromoted) {
        if (_pos.x - 1 >= 0 && _pos.y - 1 >= 0) {
            if (!_board || _board->isOccupied({_pos.x - 1, _pos.y - 1}) != _team) {
                ret.push_back({_pos.x - 1, _pos.y - 1});
            }
        }
        if (_pos.x - 1 >= 0 && _pos.y + 1 < 9) {
            if (!_board || _board->isOccupied({_pos.x - 1, _pos.y + 1}) != _team) {
                ret.push_back({_pos.x - 1, _pos.y + 1});
            }
        }
        if (_pos.x + 1 < 9 && _pos.y - 1 >= 0) {
            if (!_board || _board->isOccupied({_pos.x + 1, _pos.y - 1}) != _team) {
                ret.push_back({_pos.x + 1, _pos.y - 1});
            }
        }
        if (_pos.x + 1 < 9 && _pos.y + 1 < 9) {
            if (!_board || _board->isOccupied({_pos.x + 1, _pos.y + 1}) != _team) {
                ret.push_back({_pos.x + 1, _pos.y + 1});
            }
        }
    }

    return ret;
}

QString Rook::getPic() const
{
    if (!_isPromoted)
        return pic;
    return pic_promoted;
}
