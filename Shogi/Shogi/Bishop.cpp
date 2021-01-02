#include "Bishop.h"

Bishop::Bishop(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::Bishop, team)
{}

Bishop::Bishop(int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::Bishop, team)
{}

Bishop::Bishop(const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::Bishop, team)
{}

std::vector<Position> Bishop::getReachableFields() const
{
    return std::vector<Position>();
}
