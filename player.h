#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QString>
#include <vector>
#include <QPixmap>
#include "macros.h"
#include "compass.h"

class player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    std::vector<QPixmap> sprites_alive;
    std::vector<QPixmap> sprites_dead;
    unsigned short lives;
    bool isAlive;
    unsigned long score;
    QPoint direction;
    QPoint tmpDir;
    QTimer *switchTimer;
    Compass *compass;
    int index, add;
public slots:
    void move();
    void switchAnimate();
    void die();
public:
    player(Compass *compass_ipt);
    void cut_sprites_alive(QString name);
    void cut_sprites_dead(QString name);
    void addScore(int value);
    void setDirection(QPoint dir);
    void setScore(unsigned long newScore);
    unsigned long getScore();
    ~player();
};


#endif // PLAYER_H
