#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setFrameStyle(0);

    escena = new QGraphicsScene;
    nivel = new map(":/level1/PacmanLevel-1.png");
    pacman = new player;
    ghost_red = new ghost;
    ghost_pink = new ghost;
    ghost_cian = new ghost;
    ghost_yellow = new ghost;

    pacman->cut_sprites_dead(":/sprites/sprites.png");
    ghost_red->cut_sprites_color(":/sprites/sprites.png", "red");
    ghost_pink->cut_sprites_color(":/sprites/sprites.png", "pink");
    ghost_cian->cut_sprites_color(":/sprites/sprites.png", "cian");
    ghost_yellow->cut_sprites_color(":/sprites/sprites.png", "yellow");

    nivel->setScale(0.25);
    nivel->setPos(0, 0);
    pacman->setPos((ui->graphicsView->width()/2) -25,395);
    ghost_red->setPos(0,0);
    ghost_pink->setPos(32, 32);
    ghost_cian->setPos(64, 64);
    ghost_yellow->setPos(96, 64);

    escena->setSceneRect(0, 0, 1960, 2170);
    escena->addItem(nivel);
    escena->addItem(pacman);
    escena->addItem(ghost_red);
    escena->addItem(ghost_pink);
    escena->addItem(ghost_cian);
    escena->addItem(ghost_yellow);


    ui->graphicsView->setFixedWidth(1960);
    ui->graphicsView->setFixedHeight(2170);
    ui->graphicsView->setScene(escena);
    this->setStyleSheet("background-color: rgb(0,0,0)");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
    delete pacman;
    delete ghost_red, ghost_pink, ghost_cian, ghost_yellow;
}

