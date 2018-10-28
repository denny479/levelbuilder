#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainView->setFrameStyle(QFrame::NoFrame);
    scene = new GraphicsScene(0, 0, 1200, 751, ui->mainView);
    scene->setBackgroundBrush(QBrush(QColor(0xd6, 0xd6, 0xd6)));
    ui->mainView->setScene(scene);

    gameRect = scene->addRect(0, 0, 900, 750, QPen(QColor(0x38, 0x1e, 0x21)), QBrush(QImage("://images/background.png")));
    for (int x = 1; x < 12; x++){
        scene->addLine(x * 75, 0, x * 75, 750, QPen(QColor(0xf0, 0xf0, 0xf0)));
    }
    for (int y = 1; y < 25; y++){
        scene->addLine(0, y * 30, 900, y * 30, QPen(QColor(0xf0, 0xf0, 0xf0)));
    }
    for (int i = 0; i <= 16; i++){
        stockItems.append(scene->addItem(new NormalBlock(QPoint(925, 100 + (i * 35)) ,static_cast<NormalBlock::blockColor>(i))));
    }
    for (int i = 0; i <= 4; i++){
        stockItems.append(scene->addItem(new SolidBlock(QPoint(1005, 100 + (i * 35)) ,static_cast<SolidBlock::blockItemType>(i))));
    }

    qApp->installEventFilter(this);

    levelItems.resize(300);
    QPen pen = QPen(QBrush(QColor(Qt::black),Qt::Dense4Pattern), 3);
    highlight = scene->addRect(0, 0, 77, 32, pen);
    highlight->setPos(923, 98);
    highlight->setZValue(10);
    dragType.type = 2;
    dragType.subType = 0;
    levelDb = new Levels();

    int a = levelDb->getLevelCount() + 1;
    ui->levelBox->setValue(a);

}

MainWindow::~MainWindow()
{
    scene->clear();
    delete ui;
    delete levelDb;
}

void MainWindow::on_actionE_xit_triggered()
{
    qApp->quit();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    switch(event->type())
    {
    case QEvent::MouseButtonPress:{
        QMouseEvent *e = dynamic_cast<QMouseEvent*>(event);
        QPoint mouse = e->globalPos() - ui->mainView->mapToGlobal(QPoint(0,0));
        if (e->button() == Qt::LeftButton) {
            for(int i = 0; i < stockItems.count(); i++){
                if (stockItems[i]->getRect().contains(mouse)){
                    setCursor(QCursor(stockItems[i]->getPixmap(), 36, 14));
                    dragType.type = stockItems[i]->getType();
                    dragType.subType = stockItems[i]->getSubtype();

                    highlight->setPos(stockItems[i]->getRect().x() - 2, stockItems[i]->getRect().y() - 2);

                    return true;
                }
            }
            if (gameRect->contains(mouse)){
                int x = mouse.x() / 75;
                int y = mouse.y() / 30;
                int i = y * 12 + x;
                if (levelItems[i] != 0){
                    setCursor(QCursor(levelItems[i]->getPixmap(), 36, 14));
                    dragType.type = levelItems[i]->getType();
                    dragType.subType = levelItems[i]->getSubtype();
                    scene->removeItem(levelItems[i]);
                    delete levelItems[i];
                    levelItems[i] = 0;
                    for(int i = 0; i < stockItems.count(); i++){
                        if (stockItems[i]->getType() == dragType.type && stockItems[i]->getSubtype() == dragType.subType){
                            highlight->setPos(stockItems[i]->getRect().x() - 2, stockItems[i]->getRect().y() - 2);
                        }
                    }
                }
                return true;
            }
            return false;
        }
    }
        break;
    case QEvent::MouseButtonRelease:{
        QMouseEvent *e = dynamic_cast<QMouseEvent*>(event);
        QPoint mouse = e->globalPos() - ui->mainView->mapToGlobal(QPoint(0,0));
        if (e->button() == Qt::LeftButton) {
            setCursor(Qt::ArrowCursor);
            if (gameRect->contains(mouse)){
                int x = mouse.x() / 75;
                int y = mouse.y() / 30;
                int i = y * 12 + x;

                if (levelItems[i] != 0){
                    scene->removeItem(levelItems[i]);
                    delete levelItems[i];
                    levelItems[i] = 0;
                }
                if(dragType.type == 2){
                    levelItems[i] = scene->addItem(new NormalBlock(QPoint(x * 75 + 1, y * 30 + 1), static_cast<NormalBlock::blockColor>(dragType.subType)));
                } else {
                    levelItems[i] = scene->addItem(new SolidBlock(QPoint(x * 75 + 1, y * 30 + 1), static_cast<SolidBlock::blockItemType>(dragType.subType)));
                }
                return true;
            }
            return false;
        }
    }
        break;
    default:
        //return QObject::eventFilter(obj, event);
        return false;
        break;
    }
    return false;
}

void MainWindow::on_saveButton_clicked()
{
    int levelId = levelDb->saveLevel(ui->nameEdit->text(), ui->levelBox->value());
    for (int i = 0; i < levelItems.count(); i++){
        if(levelItems[i] != 0){
            levelDb->saveBlock(levelId, i, levelItems[i]->getType(), levelItems[i]->getSubtype(), levelItems[i]->getIsMoving());
            scene->removeItem(levelItems[i]);
            delete levelItems[i];
            levelItems[i] = 0;
        }
    }
    ui->levelBox->setValue(ui->levelBox->value() + 1);
}








