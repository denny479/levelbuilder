#include "solidblock.h"

SolidBlock::SolidBlock(QPoint p, blockItemType bType, bool moving) :
    ScreenItem(this), QGraphicsPixmapItem(QPixmap(":/images/solid.png"))
{
    blockType = bType;
    isMoving = false;

    switch(bType){
    case SOLID:
        setPixmap(QPixmap(":/images/solid.png"));
        break;
    case TOP:
        setPixmap(QPixmap(":/images/solid_top.png"));
        break;
    case SIDE:
        setPixmap(QPixmap(":/images/solid_sides.png"));
        break;
    case BOTTOM:
        setPixmap(QPixmap(":/images/solid_bot.png"));
        break;
    case TOP_BOTTOM:
        setPixmap(QPixmap(":/images/solid_top_bot.png"));
        break;
    }

    setPos(p);
    rect = QRect(p, QSize(pixmap().width(),pixmap().height()));
}

SolidBlock::~SolidBlock()
{

}

QRect SolidBlock::getRect()
{
    return rect;
}

int SolidBlock::getType()
{
    return 3;
}

int SolidBlock::getSubtype()
{
    return static_cast<int>(blockType);
}

int SolidBlock::getIsMoving()
{
    return isMoving;
}

void SolidBlock::move(QPoint pos)
{
    setPos(pos);
}

QPixmap SolidBlock::getPixmap()
{
    return pixmap();
}
