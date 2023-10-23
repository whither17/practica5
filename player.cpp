#include "player.h"

player::player()
{
    cut_sprites_alive(":/sprites/sprites.png");
    cut_sprites_dead(":/sprites/sprites.png");
}

void player::cut_sprites_alive(QString name)
{
    QPixmap image;
    image.load(name);
    sprites_alive.push_back(image.copy(0,0, sprites_weight, sprites_height));
    sprites_alive.push_back(image.copy(sprites_weight,0, sprites_weight, sprites_height));
    sprites_alive.push_back(image.copy(2*sprites_weight,0, sprites_weight, sprites_height));
    setPixmap(sprites_alive[1]);
}

void player::cut_sprites_dead(QString name)
{
    QPixmap image;
    image.load(name);
    for(int i = 0; i < sprites_weight*11; i += sprites_weight) {
        sprites_dead.push_back(image.copy(i, 1*sprites_height, sprites_weight, sprites_height));
    }
}

unsigned short player::getSpeed()
{
    return speed;
}

player::~player()
{

}


