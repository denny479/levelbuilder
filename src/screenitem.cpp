#include "screenitem.h"

ScreenItem::ScreenItem(QGraphicsItem *item) : QObject()
{
    graphicsItem = item;
    isMoving = false;
}

ScreenItem::~ScreenItem()
{

}

QGraphicsItem* ScreenItem::getGraphicsItem()
{
    return graphicsItem;
}

QRect ScreenItem::getRect()
{ return QRect(0,0,0,0);}

int ScreenItem::getType()
{return 2; }

int ScreenItem::getSubtype()
{
    return 0;
}

int ScreenItem::getIsMoving()
{
    return isMoving;
}

void ScreenItem::move(QPoint pos)
{
    (void)pos;
}

QPixmap ScreenItem::getPixmap()
{
    return QPixmap();
}
