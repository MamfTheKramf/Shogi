#include "Pawn.h"

Pawn::Pawn(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::Pawn, team)
{}

Pawn::Pawn(int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Pawn, team)
{}

Pawn::Pawn(const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Pawn, team)
{}

std::vector<Position> Pawn::getReachableFields() const {
    std::vector<Position> ret;
    if (!_isPromoted) {
        Position p = {_pos.x, _pos.y};
        if (_team == Board::Team::Black) {
            p.y -= 1;
        } else {
            p.y += 1;
        }
        // if piece would step out of the board
        if (p.y < 0 || p.y >= 9) {
            return ret;
        }
        ret.push_back(p);
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
