#include "Lance.h"

const QString Lance::pic(":/assets/Assets/lance.png");

Lance::Lance(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::Lance, team)
{}

Lance::Lance(int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Lance, team)
{}

Lance::Lance(const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Lance, team)
{}

std::vector<Position> Lance::getReachableFields() const
{

    if(!_isPromoted) {
        std::vector<Position> ret;
        int offset = 1;
        while ((_team == Board::Team::Black && _pos.y - offset >= 0)
               || (_team == Board::Team::White && _pos.y + offset < 9)) {
            int y = _team == Board::Team::Black ? _pos.y - offset : _pos.y + offset;
            ret.push_back({_pos.x, y});
            offset++;
        }
        return ret;
    } else {
        return getGoldGeneralReachableFields();
    }
}

QString Lance::getPic() const
{
    return pic;
}
