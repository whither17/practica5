#ifndef PELLET_H
#define PELLET_H

#include "item.h"
#include "macros.h"

class pellet : public Item
{
    Q_OBJECT
public:
    pellet();
    void sprite(QString name);
    void eaten();
public slots:
    void shine();
signals:
    void pelletEaten();
private:
    bool pop;
};

#endif // PELLET_H
