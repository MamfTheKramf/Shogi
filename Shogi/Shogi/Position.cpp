#include "Position.h"

Position::Position():
    x(-1),
    y(-1)
{}

Position::Position(int x, int y):
    x(x),
    y(y)
{}

Position::Position(const Position &pos):
    x(pos.x),
    y(pos.y)
{}

Position &Position::operator=(const Position &p)
{
    x = p.x;
    y = p.y;
    return *this;
}

bool Position::operator==(const Position &p)
{
    return x == p.x && y == p.y;
}
