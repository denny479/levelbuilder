#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "screenitem.h"
#include "normalblock.h"
#include "solidblock.h"
#include "graphicsscene.h"
#include <QGraphicsItem>
#include <QMouseEvent>
#include "levels.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionE_xit_triggered();
    void on_saveButton_clicked();

private:
    virtual bool eventFilter(QObject *, QEvent *);

    Ui::MainWindow *ui;
    GraphicsScene *scene;

    QList<ScreenItem*> stockItems;
    QVector<ScreenItem*> levelItems;
    QGraphicsRectItem *gameRect;
    QGraphicsRectItem *highlight;

    struct dragItem{
        int type;
        int subType;
    };
    dragItem dragType;

    Levels *levelDb;

};

#endif // MAINWINDOW_H
