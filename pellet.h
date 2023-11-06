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
    void shine();
};

#endif // PELLET_H
