#include "King.h"
#include <QDebug>

const QString King::blackPic(":/assets/Assets/blackKing.png");
const QString King::whitePic(":/assets/Assets/whiteKing.png");

King::King(Board::Team team):
    Piece({0, 0}, false, false, Piece::Type::King, team)
{}

King::King(int x, int y, Board::Team team):
    Piece({x, y}, false, false, Piece::Type::King, team)
{}

King::King(const Position &p, Board::Team team):
    Piece(p, false, false, Piece::Type::King, team)
{}

King::King(Board *board, int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::King, team, board)
{}

King::King(Board *board, const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::King, team, board)
{}

std::vector<Position> King::getReachableFields() const
{
    std::vector<Position> ret;
    for (int x = _pos.x - 1; x <= _pos.x + 1; x++) {
        if (x < 0 || x >= 9) {
            continue;
        }
        for (int y = _pos.y - 1; y <= _pos.y + 1; y++) {
            if (y >= 0 && y < 9) {
                Board::Team opp = _team == Board::Team::Black ? Board::Team::White : Board::Team::Black;
                if ((_board && (_board->isOccupied({x, y}) == _team
                                || !_board->isSafe({x, y}, opp)))
                        || _pos == Position(x, y)) {
                    continue;
                }
                ret.push_back({x, y});
            }
        }
    }
    return ret;
}

QString King::getPic() const
{
    if (_team == Board::Team::Black) {
        return blackPic;
    }
    return whitePic;
}
