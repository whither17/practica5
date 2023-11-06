#include "dot.h"

dot::dot()
{
    sprite(":/sprites/sprites.png");

}

void dot::sprite(QString name)
{
    QPixmap image;
    image.load(name);
    setPixmap(image.copy(sprites_height, 9*sprites_height, sprites_weight, sprites_height));

}

void dot::eaten() {
    emit dotEaten();
    delete this;
}

void dot::shine() {

}
