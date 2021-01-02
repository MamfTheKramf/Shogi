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

Board::Board(QWidget *parent) : QWidget(parent)
{
    resize(9 * _fieldWidth + 10, 11 * _fieldWidth + 10);
    update();
}

void Board::mousePressEvent(QMouseEvent *event)
{

}

void Board::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    QBrush brush;
    painter.fillRect(10, 10, 20, 20, Qt::red);
    painter.end();
}

void Board::initBoard()
{

}
