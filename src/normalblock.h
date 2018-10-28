#ifndef NORMALBLOCK_H
#define NORMALBLOCK_H

#include "screenitem.h"
#include <QGraphicsRectItem>
//#include <QColor>

class NormalBlock : public ScreenItem, public QGraphicsRectItem
{
public:
    enum blockColor{
        BLUE = 0,
        YELLOW = 1,
        RED = 2,
        WHITE = 3,
        BLACK = 4,
        GREEN = 5,
        LIGHTGRAY = 6,
        CYAN = 7,
        MAGENTA = 8,
        GRAY = 9,
        DARKRED = 10,
        DARKBLUE = 11,
        DARKCYAN = 12,
        DARKMAGENTA = 13,
        DARKGRAY = 14,
        DARKGREEN = 15,
        DARKYELLOW = 16
    };

    NormalBlock(QPoint p, NormalBlock::blockColor color);
    ~NormalBlock();

    QRect getRect();
    int getType();
    int getSubtype();
    int getIsMoving();
    void move(QPoint pos);
    QPixmap getPixmap();

private:
    QRect rect;
    blockColor subtype;
    QPixmap pixmap;
};

#endif // NORMALBLOCK_H
