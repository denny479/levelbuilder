#ifndef LEVELS_H
#define LEVELS_H

#include <QVariant>
#include <QSqlDatabase>
#include <QSqlQuery>
//#include <QSqlRecord>
#include <QSqlError>
#include "screenitem.h"
#include "normalblock.h"
#include "solidblock.h"

class Levels
{
public:
    Levels();
    ~Levels();

    struct levelItem{
        QPoint loc;
        ScreenItem::screenType type;
        int subType;
        bool isMoving;
    };

    int getLevelCount();
    QList<levelItem> loadLevel(int level);
    int saveLevel(QString name, int level);
    void saveBlock(int level, int loc, int type, int subtype, int moving);

private:
    QSqlDatabase db;
};

#endif // LEVELS_H
