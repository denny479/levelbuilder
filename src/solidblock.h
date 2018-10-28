#ifndef SOLIDBLOCK_H
#define SOLIDBLOCK_H

#include "screenitem.h"
#include <QGraphicsPixmapItem>

class SolidBlock : public ScreenItem, public QGraphicsPixmapItem
{
public:
    enum blockItemType{
        SOLID = 0,
        TOP = 1,
        SIDE = 2,
        BOTTOM = 3,
        TOP_BOTTOM = 4
    };

    SolidBlock(QPoint p, blockItemType bType = SOLID, bool moving = false);
    ~SolidBlock();

    QRect getRect();
    int getType();
    int getSubtype();
    int getIsMoving();
    void move(QPoint pos);
    QPixmap getPixmap();
    //QGraphicsItem* getGraphicsItem();

private:
    QRect rect;
    blockItemType blockType;
    bool isMoving;
};

#endif // SOLIDBLOCK_H
