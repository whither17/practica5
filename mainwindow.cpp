#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setFrameStyle(0);
    this->setFixedSize(width_, height_+50);
    setWindowIcon(QIcon(":/icon/icon.png"));
    //setStyleSheet("background-color: rgb(0,0,0)");
    compass = new Compass(this);
    escena = new QGraphicsScene;
    nivel = new map(":/level1/level1.png");
    score = new QGraphicsTextItem("Score: ");
    puntos = new QGraphicsTextItem("0");
    score->setDefaultTextColor(Qt::white);
    score->setFont(QFont("Joystix", 18));
    puntos->setDefaultTextColor(Qt::white);
    puntos->setFont(QFont("Joystix", 18));
    escena->setSceneRect(28,50, width_, height_-100);
    nivel->setScale(2);
    nivel->setPos(7,10);

    pacman = new player(compass);
    ghost_red = new ghost("red", compass);
    ghost_pink = new ghost("pink", compass);
    ghost_cian = new ghost("cian", compass);
    ghost_yellow = new ghost("yellow", compass);
    pacmanMove = new QTimer(this);

    pacmanMove->start(20);
    compass->initMap();
    escena->addItem(nivel);
    escena->addItem(pacman);
    escena->addItem(ghost_red);
    escena->addItem(ghost_pink);
    escena->addItem(ghost_cian);
    escena->addItem(ghost_yellow);
    escena->addItem(score);
    escena->addItem(puntos);
    score->setPos(30,10);
    puntos->setPos(100,10);
    pacman->setPos(width_/2 , 403);
    remainDots = 240;

    connect(compass, SIGNAL(eat(QPoint)), this, SLOT(dotsAte(QPoint)));
    connect(pacmanMove, SIGNAL(timeout()), pacman, SLOT(move()));

    ghost_red->setPos(width_/2,0);
    ghost_pink->setPos((ui->graphicsView->width()/2) -57, 259);
    ghost_cian->setPos((ui->graphicsView->width()/2) -25, (ui->graphicsView->height()/2)-32);
    ghost_yellow->setPos((ui->graphicsView->width()/2)+10,(ui->graphicsView->height()/2)-32);
    putDots();
    ui->graphicsView->setFixedWidth(490);
    ui->graphicsView->setFixedHeight(543);
    ui->graphicsView->setScene(escena);
}

void MainWindow::keyPressEvent(QKeyEvent *event)

{
    if ((event->key() == Qt::Key_W))
        pacman->setDirection(Dir::Up);
    else if ((event->key() == Qt::Key_S))
        pacman->setDirection(Dir::Down);
    else if ((event->key() == Qt::Key_A))
        pacman->setDirection(Dir::Left);
    else if ((event->key() == Qt::Key_D))
        pacman->setDirection(Dir::Right);
}

void MainWindow::putDots()
{
    QList <QPoint> list = compass->dots();
    foreach(QPoint pos, list)
    {
        item[pos.x()][pos.y()] = new dot;
        item[pos.x()][pos.y()]->setPos(16 * pos.y(),35+16*pos.x());
        escena->addItem(item[pos.x()][pos.y()]);
    }
    list = compass->pellets();
    foreach (QPoint pos, list)
    {
        item[pos.x()][pos.y()] = new pellet;
        item[pos.x()][pos.y()]->setPos(16 * pos.y(),35+16*pos.x());
        escena->addItem(item[pos.x()][pos.y()]);
    }
}

void MainWindow::dotsAte(QPoint pos)
{
    item[pos.x()][pos.y()]->eaten();
    pacman->addScore(10);
    puntos->setPlainText(QString::number(pacman->getScore()));
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete escena;
    delete score;
    delete pacman;
    delete compass;
    delete ghost_red;
    delete ghost_pink;
    delete ghost_cian;
    delete ghost_yellow;
}

