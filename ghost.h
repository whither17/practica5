#ifndef GHOST_H
#define GHOST_H

#include <QObject>
#include <iostream>
#include <vector>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QTimer>
#include <random>
#include "macros.h"
#include "compass.h"
#include "player.h"

class ghost : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    std::vector <QPixmap> sprites_color;
    std::vector <QPixmap> sprites_azules;
    std::vector <QPixmap> ojos;
    player *ply;
    QPointF direction;
    QPoint tmpDir;
    QTimer *switchTimer;
    Compass *compass;
    bool nerf, isAlive;
    int index_i, index_j, index_o, i;
public slots:
    void move();
    void switchAnimate();
    void nerfInterval();
    void kill();
public:
    ghost(QString name, Compass *compass_ipt, player *ply);
    void cut_sprites_color(QString name, QString color);
    void cut_sprites_azules(QString name);
    void cut_sprites_ojos(QString name);
    void collidPacman();
    ~ghost();
signals:
    void fail();
    void dead();
};

#endif // GHOST_H
