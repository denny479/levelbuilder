#ifndef SCREENITEM_H
#define SCREENITEM_H

#include <QRect>
#include <QGraphicsItem>

typedef unsigned char byte;

class ScreenItem : public QObject
{
    Q_OBJECT

public:
    ScreenItem(QGraphicsItem *item);
    virtual ~ScreenItem();

    enum screenType{
        NORMAL_BLOCK = 2,
        SOLID_BLOCK = 3,
    };

    virtual QRect getRect();
    virtual int getType();
    virtual int getSubtype();
    virtual int getIsMoving();
    virtual void move(QPoint pos);
    virtual QPixmap getPixmap();

    QGraphicsItem* getGraphicsItem();


protected:
    QGraphicsItem *graphicsItem;
    screenType itemType;
    bool isMoving;
};

#endif // SCREENITEM_H
