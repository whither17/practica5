#ifndef GHOST_RED_H
#define GHOST_RED_H


#include <QTimer>
#include <QObject>
#include <QString>
#include <cmath>
#include <QDebug>
#include "character.h"
#include "ghost.h"
#include "compass.h"

class ghostRed: public ghost {
    Q_OBJECT
public:
    ghostRed(Compass *compass_ipt);
    QPoint setTarget();

private:
    Compass *compass;
};
#endif // GHOST_RED_H
