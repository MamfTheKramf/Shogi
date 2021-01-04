#include "Rook.h"

const QString Rook::pic(":/assets/Assets/Rook.png");

Rook::Rook(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::Rook, team)
{}

Rook::Rook(int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Rook, team)
{}

Rook::Rook(const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Rook, team)
{}

std::vector<Position> Rook::getReachableFields() const {
    std::vector<Position> ret;

    // up
    for (int y = _pos.y - 1; y >= 0; y--) {
        ret.push_back({_pos.x, y});
    }
    // down
    for (int y = _pos.y + 1; y < 9; y++) {
        ret.push_back({_pos.x, y});
    }
    // left
    for (int x = _pos.x - 1; x >= 0; x --) {
        ret.push_back({x, _pos.y});
    }
    // right
    for (int x = _pos.x + 1; x < 9; x ++) {
        ret.push_back({x, _pos.y});
    }

    // diagonal fields for promoted rooks
    if (_isPromoted) {
        if (_pos.x - 1 >= 0 && _pos.y - 1 >= 0) {
            ret.push_back({_pos.x - 1, _pos.y - 1});
        }
        if (_pos.x - 1 >= 0 && _pos.y + 1 < 9) {
            ret.push_back({_pos.x - 1, _pos.y + 1});
        }
        if (_pos.x + 1 < 9 && _pos.y - 1 >= 0) {
            ret.push_back({_pos.x + 1, _pos.y - 1});
        }
        if (_pos.x + 1 < 9 && _pos.y + 1 < 9) {
            ret.push_back({_pos.x + 1, _pos.y + 1});
        }
    }

    return ret;
}

QString Rook::getPic() const
{
    return pic;
}
