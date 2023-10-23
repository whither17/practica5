#ifndef GHOST_H
#define GHOST_H

#include <QObject>
#include <iostream>
#include <vector>
#include <QGraphicsPixmapItem>
#include <QString>
#include "macros.h"


class ghost : public QObject, public QGraphicsPixmapItem
{
private:
    std::vector <QPixmap> sprites_color;
    std::vector <QPixmap> sprites_azules;
    std::vector <QPixmap> ojos;
public:
    ghost();
    void cut_sprites_color(QString name, QString color);
    void cut_sprites_azules(QString name);
    void cut_sprites_ojos(QString name);

};

#endif // GHOST_H
