#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>

class map : public QObject, public QGraphicsPixmapItem
{
public:
    map(QString name);
};

#endif // MAP_H
