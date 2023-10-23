#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "macros.h"
#include "player.h"
#include "ghost.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    map *nivel;
    player *pacman;
    ghost *ghost_red, *ghost_pink, *ghost_cian, *ghost_yellow;
};
#endif // MAINWINDOW_H
