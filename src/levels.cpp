#include "levels.h"

Levels::Levels()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("levels.db");
    db.open();
    QString err = db.lastError().text();
    int a = 0;
}

Levels::~Levels()
{
    if (db.open()) db.close();
}

int Levels::getLevelCount()
{
    QSqlQuery query;
    query.exec("SELECT COUNT(Id) FROM Levels;");
    QString err =  query.lastError().text();
    query.first();
    return query.value(0).toInt();
}

QList<Levels::levelItem> Levels::loadLevel(int level)
{
    QList<levelItem> ret;
    QSqlQuery query;
    query.prepare("SELECT Location, Type, Subtype, Moving FROM Blocks WHERE LevelId=:level ORDER BY Location");
    query.bindValue(":level", level);
    query.exec();
    while (query.next()){
        levelItem item;
        int index = query.value("Location").toInt();
        item.loc = QPoint((index % 12) * 75, (index / 12) * 30);
        item.type = static_cast<ScreenItem::screenType>(query.value("Type").toInt());
        item.subType = query.value("Subtype").toInt();
        int a = query.value("Moving").toInt();
        item.isMoving = query.value("Moving").toBool();
        ret.append(item);
    }
    return ret;
}

int Levels::saveLevel(QString name, int level)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Levels (Level, Name) VALUES(:level, :name);");
    query.bindValue(":level", level);
    query.bindValue(":name", name);
    query.exec();
    query.exec("SELECT last_insert_rowid();");
    query.first();
    return query.value(0).toInt();
}

void Levels::saveBlock(int levelId, int loc, int type, int subtype, int moving)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Blocks (LevelId, Location, Type, Subtype, Moving) VALUES(:levelId, :loc, :type, :subtype, :moving);");
    query.bindValue(":levelId", levelId);
    query.bindValue(":loc", loc);
    query.bindValue(":type", type);
    query.bindValue(":subtype", subtype);
    query.bindValue(":moving", moving);
    QList<QVariant> list = query.boundValues().values();
    query.exec();

}
