#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>
#include <QTimer>
#include "map.h"
#include "macros.h"
#include "player.h"
#include "ghost.h"
#include "compass.h"
#include "character.h"
#include "item.h"
#include "dot.h"
#include "pellet.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void putDots();
    void putWalls();
    void clearDots();
    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();
public slots:
    void dotsAte(QPoint pos);

private:
    int remainDots;
    Item *item[31][28];    //arreglo de items representando el mapa (31 fil de alto,28 col de ancho)
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    Compass *compass;
    map *nivel;
    ghost *ghost_red, *ghost_pink, *ghost_cian, *ghost_yellow;
    Character *pacman;
    QGraphicsTextItem *score, *puntos;
    QTimer *pacmanMove;
};

#endif // MAINWINDOW_H
