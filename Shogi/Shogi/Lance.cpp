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
        for (int x = _pos.x-1; x <= _pos.x+1; x++) {
            if (x < 0 || x >= 9)
                continue;

            for (int y = _pos.y-1; y <= _pos.y+1; y++) {
                if (y < 0 || y >= 9)
                    continue;

                if (( (_team == Board::Team::Black && y == _pos.y+1)
                     || (_team == Board::Team::White && y == _pos.y - 1)) && x != _pos.x)
                    continue;

                if (x == _pos.x && y == _pos.y)
                    continue;

                ret.push_back({x, y});
            }
        }
        return ret;
    }
}
