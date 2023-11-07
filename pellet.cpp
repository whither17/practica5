#include "pellet.h"

pellet::pellet()
{
    sprite(":/sprites/sprites.png");
    pop = true;
}

void pellet::sprite(QString name)
{
    QPixmap image;
    image.load(name);
    setPixmap(image.copy(0, 9*sprites_height, sprites_weight, sprites_height));
}

void pellet::eaten()
{
    emit pelletEaten();
    delete this;
}

void pellet::shine()
{
    pop = !pop;
    if(pop)
    {
       show();
    }
    else hide();
}
