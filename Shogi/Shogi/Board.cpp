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

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QPixmap>

Board::Board(QWidget *parent) : QWidget(parent)
{
    int w = 9 * _fieldWidth + 2 * _offset;
    int h = 11 * _fieldWidth + 4 * _offset;
    resize(w, h);
    parent->resize(w, h);
    for (int i = 0; i < 8; i++) {
        _capturedBlack[i] = 0;
        _capturedWhite[i] = 0;
    }
    update();
}

void Board::mousePressEvent(QMouseEvent *event)
{

}

void Board::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    //look for better image
    QPixmap pic(":/assets/Assets/board.jpg");
    painter.drawPixmap(0, 0, width(), height(), pic, 0, 0, 0, 0);
    //draw capturedWhite
    int y = _offset;
    for (int i = 0; i < 8; i++) {
        int x = _offset + (i+1) * _fieldWidth;
        painter.drawRect(x, y, _fieldWidth, _fieldWidth);
    }

    //draw actual board
    for (int i = 0; i < 9; i++) {
        int y = 2 * _offset + (i+1) * _fieldWidth;
        for (int j = 0; j < 9; j++) {
            int x = _offset + j * _fieldWidth;
            painter.drawRect(x, y, _fieldWidth, _fieldWidth);
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

}
