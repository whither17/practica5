#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setFrameStyle(0);
    setWindowIcon(QIcon(":/icon/icon.png"));
    //setStyleSheet("background-color: rgb(0,0,0)");
    escena = new QGraphicsScene;
    nivel = new map(":/level1/PacmanLevel-1.png");
    pacman = new player;
    ghost_red = new ghost("red");
    ghost_pink = new ghost("pink");
    ghost_cian = new ghost("cian");
    ghost_yellow = new ghost("yellow");

    nivel->setScale(0.25);
    nivel->setPos(0, 0);
    pacman->setPos((ui->graphicsView->width()/2) -25,395);
    ghost_red->setPos((ui->graphicsView->width()/2) -25,(ui->graphicsView->height()/2)-96);
    ghost_pink->setPos((ui->graphicsView->width()/2) -57, (ui->graphicsView->height()/2)-32);
    ghost_cian->setPos((ui->graphicsView->width()/2) -25, (ui->graphicsView->height()/2)-32);
    ghost_yellow->setPos((ui->graphicsView->width()/2)+10,(ui->graphicsView->height()/2)-32);

    escena->setSceneRect(0, 0, 490, 542);
    escena->addItem(nivel);
    escena->addItem(pacman);
    escena->addItem(ghost_red);
    escena->addItem(ghost_pink);
    escena->addItem(ghost_cian);
    escena->addItem(ghost_yellow);

    ui->graphicsView->setFixedWidth(490);
    ui->graphicsView->setFixedHeight(543);
    ui->graphicsView->setScene(escena);
}

void MainWindow::keyPressEvent(QKeyEvent *i)

{
    if(i->key() == Qt::Key_W) {
        pacman->setTransformOriginPoint(sprites_weight/2, sprites_height/2);
        pacman->setRotation(270);
        pacman->setY(pacman->y() - pacman->getSpeed());
    }
    if(i->key() == Qt::Key_S) {
        pacman->setTransformOriginPoint(sprites_weight/2, sprites_height/2);
        pacman->setRotation(90);
        pacman->setY(pacman->y() + pacman->getSpeed());
    }
    if(i->key() == Qt::Key_A) {
        pacman->setTransformOriginPoint(sprites_weight/2, sprites_height/2);
        pacman->setRotation(180);
        pacman->setX(pacman->x() - pacman->getSpeed());
    }
    if(i->key() == Qt::Key_D) {
        pacman->setTransformOriginPoint(sprites_weight/2, sprites_height/2);
        pacman->setRotation(0);
        pacman->setX(pacman->x() + pacman->getSpeed());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
    delete nivel;
    delete pacman;
    delete ghost_red;
    delete ghost_pink;
    delete ghost_cian;
    delete ghost_yellow;
}

