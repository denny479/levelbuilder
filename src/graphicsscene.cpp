#include "graphicsscene.h"


GraphicsScene::GraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent) :
    QGraphicsScene(x, y, width, height, parent)
{

}

GraphicsScene::~GraphicsScene()
{

}

//QList<ScreenItem*> GraphicsScene::items()
//{
//    return activeItems;
//}

//QList<ScreenItem *> GraphicsScene::items(ScreenItem::screenType type)
//{
//    QList<ScreenItem*> ret;
//    for (int i = 0; i < activeItems.length(); i++){
//        if (activeItems[i]->getType() == type){
//            ret.append(activeItems[i]);
//        }
//    }
//    return ret;
//}

NormalBlock* GraphicsScene::addItem(NormalBlock *item)
{
    QGraphicsScene::addItem(item);
    activeItems.append(item);
    return item;
}

SolidBlock* GraphicsScene::addItem(SolidBlock *item)
{
    QGraphicsScene::addItem(item);
    activeItems.append(item);
    return item;
}


void GraphicsScene::removeItem(ScreenItem *item)
{
    QGraphicsScene::removeItem(item->getGraphicsItem());
    activeItems.removeOne(item);
}

