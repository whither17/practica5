#ifndef DOT_H
#define DOT_H

#include "item.h"
#include "macros.h"

class dot: public Item {
    Q_OBJECT
public:
    dot();
    void sprite(QString name);
    void eaten();
    void shine();
signals:
    void dotEaten();


};

#endif // DOT_H

