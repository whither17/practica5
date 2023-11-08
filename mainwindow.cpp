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
    ghost_yellow = new ghost("yellow", compass, pacman);
    pacmanMove = new QTimer(this);
    pelletShine = new QTimer(this);

    pacmanMove->start(20);
    pelletShine->start(80);
    compass->initMap();
    escena->addItem(nivel);
    escena->addItem(pacman);
    escena->addItem(ghost_yellow);
    escena->addItem(score);
    escena->addItem(puntos);
    score->setPos(30,10);
    puntos->setPos(100,10);
    pacman->setPos(width_/2 , 403);
    remainDots = 240;

    connect(compass, SIGNAL(eat(QPoint)), this, SLOT(dotsAte(QPoint)));
    connect(pacmanMove, SIGNAL(timeout()), pacman, SLOT(move()));
    connect(pacmanMove, SIGNAL(timeout()), ghost_yellow, SLOT(move()));
    connect(ghost_yellow, SIGNAL(fail()), pacman, SLOT(die()));


    ghost_yellow->setPos(width_/2,259-47);
    putDots();
    ui->graphicsView->setFixedWidth(490);
    ui->graphicsView->setFixedHeight(543);
    ui->graphicsView->setScene(escena);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_W))
        pacman->setDirection(Up);
    else if ((event->key() == Qt::Key_S))
        pacman->setDirection(Down);
    else if ((event->key() == Qt::Key_A))
        pacman->setDirection(Left);
    else if ((event->key() == Qt::Key_D))
        pacman->setDirection(Right);
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
        connect(pelletShine, SIGNAL(timeout()),  item[pos.x()][pos.y()], SLOT(shine()));
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
    delete ghost_yellow;
}

