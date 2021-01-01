#include "Pawn.h"

Pawn::Pawn(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::Pawn, team)
{}

Pawn::Pawn(int x, int y, Board::Team team):
    Piece({x, y}, false, true, Piece::Type::Pawn, team)
{}

Pawn::Pawn(const Position &p, Board::Team team):
    Piece(p, false, true, Piece::Type::Pawn, team)
{}

std::vector<Position> Pawn::getReachableFields() const {
    // when the piece is still in the game
    if (_pos.x >= 0 && _pos.y >= 0) {
        std::vector<Position> ret;
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

    // when the piece is captured
    // TODO: implement this case
    } else {
        return std::vector<Position>();
    }
}
