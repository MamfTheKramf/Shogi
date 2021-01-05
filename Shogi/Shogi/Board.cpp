#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Lance.h"
#include "Knight.h"
#include "SilverGeneral.h"
#include "GoldGeneral.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"

#include <random>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QPixmap>
#include <QImage>
#include <QTransform>
#include <QMouseEvent>
#include <QDebug>

Board::Board(QWidget *parent) : QWidget(parent)
{
    int w = 9 * _fieldWidth + 2 * _offset;
    int h = 11 * _fieldWidth + 4 * _offset;
    resize(w, h);
    if (parent) {
        parent->resize(w, h);
    }
    for (int i = 0; i < 8; i++) {
        _capturedBlack[i] = 0;
        _capturedWhite[i] = 0;
    }
    initBoard();
    update();
}

void Board::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    Position p = getClickedField(x, y);
    if (_data[p.x][p.y]) {
        _selectedField = p;
        _highlightedFields = _data[p.x][p.y]->getReachableFields();
    }
    update();
}

void Board::paintEvent(QPaintEvent * /*event*/)
{

    QPainter painter;
    painter.begin(this);
    //look for better image
    QPixmap pic(":/assets/Assets/board.jpg");
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.drawPixmap(0, 0, width(), height(), pic, 0, 0, 0, 0);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    //draw capturedWhite
    int y = _offset;
    for (int i = 0; i < 8; i++) {
        int x = _offset + (i+1) * _fieldWidth;
        painter.drawRect(x, y, _fieldWidth, _fieldWidth);
    }

    //draw actual board
    QBrush original = painter.brush();
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
    for (int i = 0; i < 8; i++) {
        int x = _offset + i * _fieldWidth;
        painter.drawRect(x, y, _fieldWidth, _fieldWidth);
    }

    painter.end();
}

void Board::initBoard()
{
    _boardBlack.reserve(20);
    _boardWhite.reserve(20);

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
        auto renderHints = painter->renderHints();
        painter->setRenderHint(QPainter::HighQualityAntialiasing);
        painter->drawPixmap(x, y, w, h, pic, 0, 0, 0, 0);
        painter->setRenderHints(renderHints);
    }
}

Position Board::getClickedField(int x, int y) const
{
    // we clicked on whiteCaptured block
    if (y >= _offset && y <= 2*_offset + _fieldWidth) {
        return {-1, -1};
    // we clicked on the main board
    } else if (y >= 2*_offset + _fieldWidth && y <= 3*_offset + 10*_fieldWidth) {
        Position ret;
        ret.x = (x - _offset) / _fieldWidth;
        ret.y = (y - 2*_offset - _fieldWidth) / _fieldWidth;
        return ret;
    // we clicked on blackCaptured block
    } else if (y >= 3*_offset + 10*_fieldWidth && y <= height() - _offset) {
        return {-1, -1};
    }
    return {-1, -1};
}
