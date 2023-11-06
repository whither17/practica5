#ifndef GHOST_H
#define GHOST_H

#include <QObject>
#include <iostream>
#include <vector>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QTimer>
#include "macros.h"
#include "compass.h"
#include "character.h"


class ghost : public QObject, public QGraphicsPixmapItem
{
private:
    std::vector <QPixmap> sprites_color;
    std::vector <QPixmap> sprites_azules;
    std::vector <QPixmap> ojos;
    QPointF direction;
    QPoint tmpDir;
    QPoint target;
    QPoint critical;
    QTimer *switchTimer, *chaseTimer, *nerfTimer, *shine;
    Compass *compass;
    bool nerf, isAlive;
    int index_i, index_j;
    int mode, prevMode;
    int remainNerf;
    qreal step_size;
    char kind;
public slots:
    void move();
    void switchAnimate();
public:
    ghost(QString name, Compass *compass_ipt);
    void cut_sprites_color(QString name, QString color);
    void cut_sprites_azules(QString name);
    void cut_sprites_ojos(QString name);
    ~ghost();
protected :
    QTimer *tmr;
    bool home;
    enum Mode {
        Scatter, Frighten, Chase, Dead, Home, End
    };

};

#endif // GHOST_H
