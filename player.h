#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QString>
#include <vector>
#include "character.h"
#include <QPixmap>
#include "macros.h"
#include "compass.h"

class player : public Character
{
    Q_OBJECT
private:
    std::vector<QPixmap> sprites_alive;
    std::vector<QPixmap> sprites_dead;
    unsigned short lives;
    unsigned short speed;
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
public:
    player(Compass *compass_ipt);
    void cut_sprites_alive(QString name);
    void cut_sprites_dead(QString name);
    void addScore(int value);
    void setDirection(QPoint dir);
    /*
    void start();
    void pause();
    void die();
    void restore();
*/
    ~player();
    void setScore(unsigned long newScore);
    unsigned long getScore();
};


#endif // PLAYER_H
