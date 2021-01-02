#include "Lance.h"

Lance::Lance(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::Lance, team)
{

}

Lance::Lance(int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Lance, team)
{}

Lance::Lance(const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Lance, team)
{}

std::vector<Position> Lance::getReachableFields() const
{
    std::vector<Position> ret;
    if(!_isPromoted) {
        if (_team == Board::Team::Black) {
            ret.reserve(_pos.y);
            for(int i = 0; i < _pos.y; i++) {
                ret.push_back(Position(_pos.x, i));
            }
        } else {
            ret.reserve(8 - _pos.y);
            for(int i = 8; i > _pos.y; i--) {
                ret.push_back(Position(_pos.x, i));
            }
        }
        return ret;
    } else {
        return getGoldGeneralReachableFields();
    }
}
