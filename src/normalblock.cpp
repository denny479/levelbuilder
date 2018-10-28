#include "normalblock.h"

#include <QBrush>
#include <QPen>

NormalBlock::NormalBlock(QPoint p, blockColor color) :
    ScreenItem(this), QGraphicsRectItem()
{
    subtype = color;
    QColor _color;
    switch(color){
    case BLUE:
        _color = Qt::blue;
        break;
    case YELLOW:
        _color = Qt::yellow;
        break;
    case RED:
        _color = Qt::red;
        break;
    case WHITE:
        _color = Qt::white;
        break;
    case BLACK:
        _color = Qt::black;
        break;
    case GREEN:
        _color = Qt::green;
        break;
    case LIGHTGRAY:
        _color = Qt::lightGray;
        break;
    case CYAN:
        _color = Qt::cyan;
        break;
    case MAGENTA:
        _color = Qt::magenta;
        break;
    case GRAY:
        _color = Qt::gray;
        break;
    case DARKRED:
        _color = Qt::darkRed;
        break;
    case DARKBLUE:
        _color = Qt::darkBlue;
        break;
    case DARKCYAN:
        _color = Qt::darkCyan;
        break;
    case DARKMAGENTA:
        _color = Qt::darkMagenta;
        break;
    case DARKGRAY:
        _color = Qt::darkGray;
        break;
    case DARKGREEN:
        _color = Qt::darkGreen;
        break;
    case DARKYELLOW:
        _color = Qt::darkYellow;
        break;
    }
    rect = QRect(p, QSize(73,28));
    setRect(rect);
    setPen(QPen(_color));
    setBrush(QBrush(_color));
    pixmap = QPixmap(73, 28);
    pixmap.fill(_color);
}

NormalBlock::~NormalBlock()
{

}

QRect NormalBlock::getRect()
{
    return rect;
}

int NormalBlock::getType()
{
    return 2;
}

int NormalBlock::getSubtype()
{
    return static_cast<int>(subtype);
}

int NormalBlock::getIsMoving()
{
    return 0;
}

void NormalBlock::move(QPoint pos)
{
    setPos(pos);
    rect = QRect(pos, QSize(73,28));
    QPointF p = QGraphicsItem::pos();
    int a = 0;
}

QPixmap NormalBlock::getPixmap()
{
    return pixmap;
}
