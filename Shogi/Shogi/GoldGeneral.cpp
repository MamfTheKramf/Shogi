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

std::vector<Position> GoldGeneral::getReachableFields() const
{
    return getGoldGeneralReachableFields();
}

QString GoldGeneral::getPic() const
{
    return pic;
}
