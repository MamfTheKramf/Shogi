#ifndef POSITION_H
#define POSITION_H


struct Position
{
    int x;
    int y;
    Position();

    Position(int x, int y);

    Position(const Position& pos);

    Position& operator=(const Position& p);

    bool operator==(const Position& p);
};

#endif // POSITION_H
