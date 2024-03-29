#include "SilverGeneral.h"

const QString SilverGeneral::pic(":/assets/Assets/silverGeneral.png");
const QString SilverGeneral::pic_promoted(":/assets/Assets/silverGeneral_promoted.png");

SilverGeneral::SilverGeneral(Board::Team team):
    Piece({0, 0}, false, true, Piece::Type::SilverGeneral, team)
{}

SilverGeneral::SilverGeneral(int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::SilverGeneral, team)
{}

SilverGeneral::SilverGeneral(const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::SilverGeneral, team)
{}

SilverGeneral::SilverGeneral(Board *board, int x, int y, Board::Team team, bool promoted):
    Piece({x, y}, promoted, true, Piece::Type::SilverGeneral, team, board)
{}

SilverGeneral::SilverGeneral(Board *board, const Position &p, Board::Team team, bool promoted):
    Piece(p, promoted, true, Piece::Type::SilverGeneral, team, board)
{}

std::vector<Position> SilverGeneral::getReachableFields(bool includeFriendlyFields) const {
    if (!_isPromoted) {
        std::vector<Position> ret;
        // row in front
        int y = _team == Board::Team::Black ? _pos.y - 1 : _pos.y + 1;
        if (y >= 0 && y < 9) { //only when y is in bound
            for (int x = _pos.x - 1; x <= _pos.x + 1; x++) {
                if (x >= 0 && x < 9) {
                    if (includeFriendlyFields || !_board || _board->isOccupied({x, y}) != _team) {
                        ret.push_back({x, y});
                    }
                }
            }
        }

        // two diagonal back fields
        y = _team == Board::Team::Black ? _pos.y + 1 : _pos.y - 1;
        if (y >= 0 && y < 9) {
            if (_pos.x - 1 >= 0 && (includeFriendlyFields || !_board || _board->isOccupied({_pos.x - 1, y}) != _team)) {
                ret.push_back({_pos.x - 1, y});
            }
            if (_pos.x + 1 < 9 && (includeFriendlyFields || !_board || _board->isOccupied({_pos.x + 1, y}) != _team)) {
                ret.push_back({_pos.x + 1, y});
            }
        }

        return ret;

    } else {
        return getGoldGeneralReachableFields(includeFriendlyFields);
    }
}

QString SilverGeneral::getPic() const
{
    if (!_isPromoted)
        return pic;
    return pic_promoted;
}
