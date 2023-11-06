#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include "item.h"

class map : public QObject, public QGraphicsPixmapItem
{
public:
    map(QString name);
    ~map();
};

#endif // MAP_H
