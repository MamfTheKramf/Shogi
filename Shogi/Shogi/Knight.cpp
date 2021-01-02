#include "Knight.h"

Knight::Knight(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::Knight, team)
{}

Knight::Knight(int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Knight, team)
{}

Knight::Knight(const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Knight, team)
{}

std::vector<Position> Knight::getReachableFields() const
{
    if(!_isPromoted) {
        std::vector<Position> ret;
        int y = _team == Board::Team::Black ? _pos.y - 2 : _pos.y + 2;
        if (y < 0 || y >= 9)
            return ret;

        // since we can't overshoot the right border by substracting 1 from the x-Pos, we only check one side
        if (_pos.x - 1 >= 0)
            ret.push_back({_pos.x - 1, y});

        if (_pos.x + 1 < 9)
            ret.push_back({_pos.x + 1, y});

        return ret;
    } else {
        return getGoldGeneralReachableFields();
    }
}
