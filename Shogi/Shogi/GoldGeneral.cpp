#include "GoldGeneral.h"

const QString GoldGeneral::pic(":/assets/Assets/goldGeneral.png");

GoldGeneral::GoldGeneral(Board::Team team):
    Piece({0, 0}, false, false, Piece::Type::GoldGeneral, team)
{}

GoldGeneral::GoldGeneral(int x, int y, Board::Team team):
    Piece({x, y}, false, false, Piece::Type::GoldGeneral, team)
{}

GoldGeneral::GoldGeneral(const Position &p, Board::Team team):
    Piece(p, false, false, Piece::Type::GoldGeneral, team)
{}

GoldGeneral::GoldGeneral(Board *board, int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::GoldGeneral, team, board)
{}

GoldGeneral::GoldGeneral(Board *board, const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::GoldGeneral, team, board)
{}

std::vector<Position> GoldGeneral::getReachableFields(bool includeFriendlyFields) const
{
    return getGoldGeneralReachableFields(includeFriendlyFields);
}

QString GoldGeneral::getPic() const
{
    return pic;
}
