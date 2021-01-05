#include "Bishop.h"

const QString Bishop::pic(":/assets/Assets/bishop.png");

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
        ret.push_back({_pos.x - offset, _pos.y - offset});
        offset++;
    }
    // up-right direction
    offset = 1;
    while (_pos.x + offset < 9 && _pos.y - offset >= 0) {
        ret.push_back({_pos.x + offset, _pos.y - offset});
        offset++;
    }
    // down-left direction
    offset = 1;
    while (_pos.x - offset >= 0 && _pos.y + offset < 9) {
        ret.push_back({_pos.x - offset, _pos.y + offset});
        offset++;
    }
    // down-right direction
    offset = 1;
    while (_pos.x + offset < 9 && _pos.y + offset < 9) {
        ret.push_back({_pos.x + offset, _pos.y + offset});
        offset++;
    }

    // pomoted extra
    if (_isPromoted) {
        if (_pos.x - 1 >= 0) { ret.push_back({_pos.x - 1, _pos.y}); }
        if (_pos.x + 1 < 9) { ret.push_back({_pos.x + 1, _pos.y}); }
        if (_pos.y - 1 >= 0) { ret.push_back({_pos.x, _pos.y - 1}); }
        if (_pos.y + 1 < 9) { ret.push_back({_pos.x, _pos.y + 1}); }
    }

    return ret;
}

QString Bishop::getPic() const
{
    return pic;
}
