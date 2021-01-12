#include "Knight.h"

const QString Knight::pic(":/assets/Assets/knight.png");
const QString Knight::pic_promoted(":/assets/Assets/knight_promoted.png");

Knight::Knight(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::Knight, team)
{}

Knight::Knight(int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Knight, team)
{}

Knight::Knight(const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Knight, team)
{}

Knight::Knight(Board *board, int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Knight, team, board)
{}

Knight::Knight(Board *board, const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Knight, team, board)
{}

std::vector<Position> Knight::getReachableFields() const
{
    if(!_isPromoted) {
        std::vector<Position> ret;
        int y = _team == Board::Team::Black ? _pos.y - 2 : _pos.y + 2;
        if (y < 0 || y >= 9)
            return ret;

        // since we can't overshoot the right border by substracting 1 from the x-Pos, we only check one side
        if (_pos.x - 1 >= 0
                && (!_board || _board->isOccupied({_pos.x-1, y}) != _team))
            ret.push_back({_pos.x - 1, y});

        if (_pos.x + 1 < 9
                && (!_board || _board->isOccupied({_pos.x+1, y}) != _team))
            ret.push_back({_pos.x + 1, y});

        return ret;
    } else {
        return getGoldGeneralReachableFields();
    }
}

QString Knight::getPic() const
{
    if (!_isPromoted)
        return pic;
    return pic_promoted;
}
