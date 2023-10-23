#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <vector>
#include "macros.h"

class player : public QObject, public QGraphicsPixmapItem
{

private:
    std::vector<QPixmap> sprites_alive;
    std::vector<QPixmap> sprites_dead;
    unsigned short lives = 3;
    unsigned short speed = 1;
    bool isalive = true;
    unsigned long score = 0;
public:
    player();
    void cut_sprites_alive(QString name);
    void cut_sprites_dead(QString name);
    unsigned short getSpeed();
    ~player();
};

#endif // PLAYER_H
