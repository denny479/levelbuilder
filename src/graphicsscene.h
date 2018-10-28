#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include "normalblock.h"
#include "solidblock.h"

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject * parent = 0);
    ~GraphicsScene();
	//QList<ScreenItem *> items();
    //QList<ScreenItem *> items(ScreenItem::screenType type);
    //void addScreenItem(ScreenItem *item);
	NormalBlock *addItem(NormalBlock *item);
	SolidBlock *addItem(SolidBlock *item);

    void removeItem(ScreenItem *item);

private:
    //QHash<QGraphicsItem*, ScreenItem*> activeItems;
    QList<ScreenItem*> activeItems;
};

#endif // GRAPHICSSCENE_H
