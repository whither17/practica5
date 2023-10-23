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
public:
    player();
    void cut_sprites_alive(QString name);
    void cut_sprites_dead(QString name);
};

#endif // PLAYER_H
