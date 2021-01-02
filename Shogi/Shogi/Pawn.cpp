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
        return getGoldGeneralReachableFields();
    }

}
