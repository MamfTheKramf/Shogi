#include "King.h"

King::King(Board::Team team):
    Piece({0, 0}, false, false, Piece::Type::King, team)
{}

King::King(int x, int y, Board::Team team):
    Piece({x, y}, false, false, Piece::Type::King, team)
{}

King::King(const Position &p, Board::Team team):
    Piece(p, false, false, Piece::Type::King, team)
{}

std::vector<Position> King::getReachableFields() const
{
    std::vector<Position> ret = getGoldGeneralReachableFields();
    // add the two missing diagonals
    if (_team == Board::Team::Black) {
        if (_pos.y + 1 < 9) {
            if (_pos.x - 1 >= 0) {
                ret.push_back({_pos.x - 1, _pos.y + 1});
            }
            if (_pos.x + 1 < 9) {
                ret.push_back({_pos.x + 1, _pos.y + 1});
            }
        }
    } else {
        if (_pos.y - 1 >= 0) {
            if (_pos.x - 1 >= 0) {
                ret.push_back({_pos.x - 1, _pos.y - 1});
            }
            if (_pos.x + 1 < 9) {
                ret.push_back({_pos.x + 1, _pos.y - 1});
            }
        }
    }
    return ret;
}