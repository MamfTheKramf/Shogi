#include "Board.h"
#include "Pawn.h"
#include "Lance.h"
#include "Knight.h"
#include "SilverGeneral.h"
#include "GoldGeneral.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"

#include <algorithm>
#include <random>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QColor>
#include <QPixmap>
#include <QImage>
#include <QTransform>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>

Board::Board(QWidget *parent) : QWidget(parent),
    _numbersBlack({0, 0, 0, 0, 0, 0, 0}),
    _numbersWhite({0, 0, 0, 0, 0, 0, 0})
{
    int w = 9 * _fieldWidth + 2 * _offset;
    int h = 11 * _fieldWidth + 4 * _offset;
    resize(w, h);
    if (parent) {
        parent->resize(w, h);
    }

    initBoard();
    _activePlayer = Board::Team::Black;
    updateWinTitle();

    _background.load(":/assets/Assets/board.jpg");

    update();
}

int Board::isOccupied(Position p)
{
    if (_data[p.x][p.y]) {
        return _data[p.x][p.y]->getTeam();
    }
    return -1;
}

bool Board::isSafe(Position p, Board::Team opponent)
{
    std::list<std::shared_ptr<Piece>>& searchSpace = opponent == Board::Team::Black ? _boardBlack : _boardWhite;
    for (auto piece : searchSpace) {
        if (piece->getType() != Piece::Type::King) {
            std::vector<Position> res = piece->getReachableFields();
            if (std::count(res.begin(), res.end(), p) > 0) {
                return false;
            }
        } else {
            if (abs(p.x - piece->getPos().x) <= 1
                    && abs(p.y - piece->getPos().y) <= 1) {
                return false;
            }
        }
    }
    return true;
}

void Board::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    Position p = getClickedField(x, y);
    if (p.x < 0) {
        return;

    // when clicked on WhiteCaptrued block
    } else if (p.y == -1) {
        if (_activePlayer != Board::Team::White) {
            return;
        }
        //check if there is a piece of the captured type
        int clickCounter = 6 - p.x;
        int clickedType = -1;
        for (int i = 0; i < 7; i++) {
            if (_numbersWhite[i] > 0) {
                clickCounter--;
                if (clickCounter < 0) {
                    clickedType = i;
                    break;
                }
            }
        }
        if (clickedType >= 0 && _numbersWhite[clickedType]) {
            _selectedField = p;
            _highlightedFields = getDropFields(clickedType);
        }

    // when clicked on BlackCaptured block
    }else if (p.y == 9) {
        if (_activePlayer != Board::Team::Black) {
            return;
        }
        int clickCounter = p.x;
        int clickedType = -1;
        for (int i = 0; i < 7; i++) {
            if (_numbersBlack[i] > 0) {
                clickCounter--;
                if (clickCounter < 0) {
                    clickedType = i;
                    break;
                }
            }
        }
        if (clickedType >= 0 && _numbersBlack[clickedType]) {
            _selectedField = p;
            _highlightedFields = getDropFields(clickedType);
        }

    } else if (_data[p.x][p.y] && _data[p.x][p.y]->getTeam() == _activePlayer) {
        _selectedField = p;
        _highlightedFields = _data[p.x][p.y]->getReachableFields();

    // when clicked on a highlighted field -> move Piece and change player
    } else if(std::count(_highlightedFields.begin(), _highlightedFields.end(), p)) {
        move(_selectedField, p);
        _selectedField = {-1, -1};
        _highlightedFields.clear();
        changePlayer();
    }


    updateWinTitle();
    update();
}

void Board::paintEvent(QPaintEvent * /*event*/)
{

    QPainter painter;
    painter.begin(this);
    QBrush original = painter.brush();

    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.drawPixmap(0, 0, width(), height(), _background, 0, 0, 0, 0);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    const int fontSize = 13;
    QFont font;
    font.setPixelSize(fontSize);
    font.setBold(true);
    painter.setFont(font);

    //draw capturedWhite
    int y = _offset;
    int x = width() - _offset - _fieldWidth;
    int counter = 6 - _selectedField.x;
    for (int i = 0; i < 7; i++) {
        if (_numbersWhite[i] > 0) {
            counter--;
            if (counter == -1 && _selectedField.y == -1) {
                QBrush b(QColor(50, 150, 50, 100));
                painter.setBrush(b);
            }
            painter.drawRect(x, y, _fieldWidth, _fieldWidth);
            painter.setBrush(original);
            QString url;
            switch(i) {
            case Piece::Type::Pawn:
                url = Pawn::pic;
                break;
            case Piece::Type::Lance:
                url = Lance::pic;
                break;
            case Piece::Type::Knight:
                url = Knight::pic;
                break;
            case Piece::Type::SilverGeneral:
                url = SilverGeneral::pic;
                break;
            case Piece::Type::GoldGeneral:
                url = GoldGeneral::pic;
                break;
            case Piece::Type::Bishop:
                url = Bishop::pic;
                break;
            case Piece::Type::Rook:
                url = Rook::pic;
                break;
            }
            drawPiece(&painter, x + _offset, y + _offset,
                      _fieldWidth - 2*_offset, _fieldWidth - 2*_offset,
                      Board::Team::White, url);
            painter.drawText(x + 2, y + _fieldWidth - 1, QString::number(_numbersWhite[i]));
            x -= _fieldWidth;
        }
    }

    //draw actual board
    for (int i = 0; i < 9; i++) {
        int y = 2 * _offset + (i+1) * _fieldWidth;
        for (int j = 0; j < 9; j++) {
            int x = _offset + j * _fieldWidth;
            if (_selectedField == Position(j, i)) {
                QBrush b(QColor(50, 150, 50, 100));
                painter.setBrush(b);
            }
            if (std::count(_highlightedFields.begin(), _highlightedFields.end(), Position(j, i)) >= 1) {
                QBrush b(QColor(50, 50, 50, 50));
                painter.setBrush(b);
            }
            painter.drawRect(x, y, _fieldWidth, _fieldWidth);
            painter.setBrush(original);
            if (_data[j][i]) {
                drawPiece(&painter, x + _offset, y + _offset,
                          _fieldWidth - 2*_offset, _fieldWidth - 2*_offset,
                          _data[j][i]->getTeam(), _data[j][i]->getPic());
            }
        }
    }

    //draw markers
    QPen p;
    p.setWidth(10);
    painter.setPen(p);
    painter.drawPoint(_offset + 3*_fieldWidth, 2*_offset + 4*_fieldWidth);
    painter.drawPoint(_offset + 6*_fieldWidth, 2*_offset + 4*_fieldWidth);
    painter.drawPoint(_offset + 6*_fieldWidth, 2*_offset + 7*_fieldWidth);
    painter.drawPoint(_offset + 3*_fieldWidth, 2*_offset + 7*_fieldWidth);
    p.setWidth(1);
    painter.setPen(p);

    //draw capturedBlack
    y = 3 * _offset + 10 * _fieldWidth;
    x = _offset;
    counter = _selectedField.x;
    for (int i = 0; i < 7; i++) {
        if (_numbersBlack[i] > 0) {
            counter--;
            if (counter == -1 && _selectedField.y == 9) {
                QBrush b(QColor(50, 150, 50, 100));
                painter.setBrush(b);
            }
            painter.drawRect(x, y, _fieldWidth, _fieldWidth);
            painter.setBrush(original);
            QString url;
            switch(i) {
            case Piece::Type::Pawn:
                url = Pawn::pic;
                break;
            case Piece::Type::Lance:
                url = Lance::pic;
                break;
            case Piece::Type::Knight:
                url = Knight::pic;
                break;
            case Piece::Type::SilverGeneral:
                url = SilverGeneral::pic;
                break;
            case Piece::Type::GoldGeneral:
                url = GoldGeneral::pic;
                break;
            case Piece::Type::Bishop:
                url = Bishop::pic;
                break;
            case Piece::Type::Rook:
                url = Rook::pic;
                break;
            }
            drawPiece(&painter, x + _offset, y + _offset,
                      _fieldWidth - 2*_offset, _fieldWidth - 2*_offset,
                      Board::Team::Black, url);
            painter.drawText(x + 2, y + _fieldWidth - 1, QString::number(_numbersBlack[i]));
            x += _fieldWidth;
        }
    }
    painter.end();
}

void Board::initBoard()
{

    // create Pawns
    for (int i = 0; i < 9; i++) {
        std::shared_ptr<Piece> bPawn = std::make_shared<Pawn>(this, i, 6, Board::Team::Black);
        std::shared_ptr<Piece> wPawn = std::make_shared<Pawn>(this, i, 2, Board::Team::White);
        _boardBlack.push_back(bPawn);
        _boardWhite.push_back(wPawn);
        _data[i][6] = bPawn;
        _data[i][2] = wPawn;
    }

    {// create Lances
        std::shared_ptr<Piece> lance = std::make_shared<Lance>(this, 0, 8, Board::Team::Black);
        _boardBlack.push_back(lance);
        _data[0][8] = lance;

        lance = std::make_shared<Lance>(this, 8, 8, Board::Team::Black);
        _boardBlack.push_back(lance);
        _data[8][8] = lance;

        lance = std::make_shared<Lance>(this, 0, 0, Board::Team::White);
        _boardWhite.push_back(lance);
        _data[0][0] = lance;

        lance = std::make_shared<Lance>(this, 8, 0, Board::Team::White);
        _boardWhite.push_back(lance);
        _data[8][0] = lance;
    }

    { //drawing Knights
        std::shared_ptr<Piece> knight = std::make_shared<Knight>(this, 1, 8, Board::Team::Black);
        _boardBlack.push_back(knight);
        _data[1][8] = knight;

        knight = std::make_shared<Knight>(this, 7, 8, Board::Team::Black);
        _boardBlack.push_back(knight);
        _data[7][8] = knight;

        knight = std::make_shared<Knight>(this, 1, 0, Board::Team::White);
        _boardWhite.push_back(knight);
        _data[1][0] = knight;

        knight = std::make_shared<Knight>(this, 7, 0, Board::Team::White);
        _boardWhite.push_back(knight);
        _data[7][0] = knight;
    }

    { //drawing SilverGenerals
        std::shared_ptr<Piece> sg = std::make_shared<SilverGeneral>(this, 2, 8, Board::Team::Black);
        _boardBlack.push_back(sg);
        _data[2][8] = sg;

        sg = std::make_shared<SilverGeneral>(this, 6, 8, Board::Team::Black);
        _boardBlack.push_back(sg);
        _data[6][8] = sg;

        sg = std::make_shared<SilverGeneral>(this, 2, 0, Board::Team::White);
        _boardWhite.push_back(sg);
        _data[2][0] = sg;

        sg = std::make_shared<SilverGeneral>(this, 6, 0, Board::Team::White);
        _boardWhite.push_back(sg);
        _data[6][0] = sg;
    }

    { //drawing GolgGenerals
        std::shared_ptr<Piece> gg = std::make_shared<GoldGeneral>(this, 3, 8, Board::Team::Black);
        _boardBlack.push_back(gg);
        _data[3][8] = gg;

        gg = std::make_shared<GoldGeneral>(this, 5, 8, Board::Team::Black);
        _boardBlack.push_back(gg);
        _data[5][8] = gg;

        gg = std::make_shared<GoldGeneral>(this, 3, 0, Board::Team::White);
        _boardWhite.push_back(gg);
        _data[3][0] = gg;

        gg = std::make_shared<GoldGeneral>(this, 5, 0, Board::Team::White);
        _boardWhite.push_back(gg);
        _data[5][0] = gg;
    }

    { //drawing Kings
        std::shared_ptr<Piece> king = std::make_shared<King>(this, 4, 8, Board::Team::Black);
        _boardBlack.push_back(king);
        _data[4][8] = king;

        king = std::make_shared<King>(this, 4, 0, Board::Team::White);
        _boardWhite.push_back(king);
        _data[4][0] = king;
    }

    { //drawing Bishops
        std::shared_ptr<Piece> bishop = std::make_shared<Bishop>(this, 1, 7, Board::Team::Black);
        _boardBlack.push_back(bishop);
        _data[1][7] = bishop;

        bishop = std::make_shared<Bishop>(this, 7, 1, Board::Team::White);
        _boardWhite.push_back(bishop);
        _data[7][1] = bishop;
    }

    { //drawing Rooks
        std::shared_ptr<Piece> rook = std::make_shared<Rook>(this, 7, 7, Board::Team::Black);
        _boardBlack.push_back(rook);
        _data[7][7] = rook;

        rook = std::make_shared<Rook>(this, 1, 1, Board::Team::White);
        _boardWhite.push_back(rook);
        _data[1][1] = rook;
    }
}

void Board::drawPiece(QPainter* painter, float x, float y, float w, float h, Board::Team team, const QString& url) const
{
    if (painter && !url.isEmpty()) {
        QPixmap pic(url);
        if (team == Board::Team::White) {
            QTransform m;
            m.rotate(180);
            pic = pic.transformed(m);
        }
        pic = pic.scaledToWidth(w, Qt::SmoothTransformation); // looks a bit better but is slower
        auto renderHints = painter->renderHints();
        painter->setRenderHint(QPainter::HighQualityAntialiasing);
        painter->drawPixmap(x, y, w, h, pic, 0, 0, 0, 0);
        painter->setRenderHints(renderHints);
    }
}

Position Board::getClickedField(int x, int y) const
{
    // we clicked on whiteCaptured block
    if (y >= _offset && y <= 2*_offset + _fieldWidth && x >= _offset + 2*_fieldWidth) {
        Position ret;
        ret.x = (x - _offset - 2*_fieldWidth) / _fieldWidth;
        ret.y = -1;
        return ret;
    // we clicked on the main board
    } else if (y >= 2*_offset + _fieldWidth && y <= 3*_offset + 10*_fieldWidth) {
        Position ret;
        ret.x = (x - _offset) / _fieldWidth;
        ret.y = (y - 2*_offset - _fieldWidth) / _fieldWidth;
        return ret;
    // we clicked on blackCaptured block
    } else if (y >= 3*_offset + 10*_fieldWidth && y <= height() - _offset && x <= _offset + 7*_fieldWidth) {
        Position ret;
        ret.x = (x - _offset) / _fieldWidth;
        ret.y = 9;
        return ret;
    }
    return {-1, -1};
}

void Board::updateWinTitle()
{
    QString title = "Active Player: ";
    if (_activePlayer == Board::Team::Black) {
        title += "Black";
    } else {
        title += "White";
    }
    setWindowTitle(title);
}

void Board::move(Position from, Position to)
{
    /*
        this method doen't check if you move a piece on another friendly piece
        this case should not happen
    */
    //drop from white
    if (from.y == -1 && _activePlayer == Board::Team::White) {
        int clickCounter = 6 - from.x;
        int clickedType = -1;
        for (int i = 0; i < 7; i++) {
            if (_numbersWhite[i] > 0) {
                clickCounter--;
                if (clickCounter < 0) {
                    clickedType = i;
                    _numbersWhite[i]--;
                    break;
                }
            }
        }
        std::shared_ptr<Piece> piece;
        switch (clickedType) {
        case Piece::Type::Pawn:
            piece = std::make_shared<Pawn>(this, to, Board::Team::White);
            break;
        case Piece::Type::Lance:
            piece = std::make_shared<Lance>(this, to, Board::Team::White);
            break;
        case Piece::Type::Knight:
            piece = std::make_shared<Knight>(this, to, Board::Team::White);
            break;
        case Piece::Type::SilverGeneral:
            piece = std::make_shared<SilverGeneral>(this, to, Board::Team::White);
            break;
        case Piece::Type::GoldGeneral:
            piece = std::make_shared<GoldGeneral>(this, to, Board::Team::White);
            break;
        case Piece::Type::Bishop:
            piece = std::make_shared<Bishop>(this, to, Board::Team::White);
            break;
        case Piece::Type::Rook:
            piece = std::make_shared<Rook>(this, to, Board::Team::White);
            break;
        default:
            return;
        }
        _boardWhite.push_back(piece);
        _data[to.x][to.y] = piece;

    //drop from black
    } else if (from.y == 9 && _activePlayer == Board::Team::Black) {
        int clickCounter = from.x;
        int clickedType = -1;
        for (int i = 0; i < 7; i++) {
            if (_numbersBlack[i] > 0) {
                clickCounter--;
                if (clickCounter < 0) {
                    clickedType = i;
                    _numbersBlack[i]--;
                    break;
                }
            }
        }
        std::shared_ptr<Piece> piece;
        switch (clickedType) {
        case Piece::Type::Pawn:
            piece = std::make_shared<Pawn>(this, to, Board::Team::Black);
            break;
        case Piece::Type::Lance:
            piece = std::make_shared<Lance>(this, to, Board::Team::Black);
            break;
        case Piece::Type::Knight:
            piece = std::make_shared<Knight>(this, to, Board::Team::Black);
            break;
        case Piece::Type::SilverGeneral:
            piece = std::make_shared<SilverGeneral>(this, to, Board::Team::Black);
            break;
        case Piece::Type::GoldGeneral:
            piece = std::make_shared<GoldGeneral>(this, to, Board::Team::Black);
            break;
        case Piece::Type::Bishop:
            piece = std::make_shared<Bishop>(this, to, Board::Team::Black);
            break;
        case Piece::Type::Rook:
            piece = std::make_shared<Rook>(this, to, Board::Team::Black);
            break;
        default:
            return;
        }
        _boardBlack.push_back(piece);
        _data[to.x][to.y] = piece;

    // regular move on board
    } else if (_data[from.x][from.y] && _data[from.x][from.y]->getTeam() == _activePlayer) {
        std::shared_ptr<Piece> piece = _data[from.x][from.y];
        // check whether piece can be promoted and ask if it should be promoted
        if (piece->isPromotable() && !piece->isPromoted()
                && ((_activePlayer == Board::Team::Black && (from.y <= 2 || to.y <= 2))
                    || (_activePlayer == Board::Team::White && (from.y >= 6 || to.y >= 6)))) {
            auto res = QMessageBox::question(this, "Promote", "Do you want to promote this piece?");
            if(res == QMessageBox::Yes) {
                piece->promote();
            }
        }

        // in case there is an enemy piece on that field, we need to take care of it
        if (_data[to.x][to.y] && _data[to.x][to.y]->getTeam() != _activePlayer) {
            std::shared_ptr<Piece> captured = _data[to.x][to.y];
            captured->setPos(-1, -1);
            if (_activePlayer == Board::Team::Black) {
                _boardWhite.remove(captured);
                _numbersBlack[captured->getType()]++;
            } else {
                _boardBlack.remove(captured);
                _numbersWhite[captured->getType()]++;
            }
        }

        piece->setPos(to.x, to.y);
        _data[to.x][to.y] = std::move(piece);
        _data[from.x][from.y].reset();
    }
}

void Board::changePlayer()
{
    if(_activePlayer == Board::Team::Black) {
        _activePlayer = Board::Team::White;
    } else {
        _activePlayer = Board::Team::Black;
    }
}

std::vector<Position> Board::getDropFields(int type)
{
    if (type == Piece::Type::Pawn) {
        std::vector<Position> ret;
        std::array<bool, 9> colBlocked{false};
        if (_activePlayer == Board::Team::Black) {
            for (auto p : _boardBlack) {
                if (p->getType() == type) {
                    colBlocked[p->getPos().x] = true;
                }
            }
        } else {
            for (auto p : _boardWhite) {
                if (p->getType() == type) {
                    colBlocked[p->getPos().x] = true;
                }
            }
        }
        for (int x = 0; x < 9; x++) {
            if (colBlocked[x]) {
                continue;
            }
            for (int y = 1; y < 8; y++) {
                // add field only if it is free
                if (!_data[x][y]) {
                    ret.emplace_back(x, y);
                }
            }
            if (_activePlayer == Board::Team::Black
                    && !_data[x][8]) {
                ret.emplace_back(x, 8);
            } else if (_activePlayer == Board::Team::White
                       && !_data[x][0]) {
                ret.emplace_back(x, 0);
            }
        }
        return ret;
    } else if (type == Piece::Type::Lance) {
        std::vector<Position> ret;
        for (int x = 0; x < 9; x++) {
            for (int y = 1; y < 8; y++) {
                if (!_data[x][y]) {
                    ret.emplace_back(x, y);
                }
            }
            if (_activePlayer == Board::Team::Black
                    && !_data[x][8]) {
                ret.emplace_back(x, 8);
            } else if (_activePlayer == Board::Team::White
                       && !_data[x][0]) {
                ret.emplace_back(x, 0);
            }
        }
        return ret;
    } else if (type == Piece::Type::Knight) {
        std::vector<Position> ret;
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if ((y < 2 && _activePlayer == Board::Team::Black)
                        || (y > 6 && _activePlayer == Board::Team::White)) {
                    continue;
                }
                if (!_data[x][y]) {
                    ret.emplace_back(x, y);
                }
            }
        }
        return ret;
    } else {
        std::vector<Position> ret;
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if (!_data[x][y]) {
                    ret.emplace_back(x, y);
                }
            }
        }
        return ret;
    }
    return {};
}
