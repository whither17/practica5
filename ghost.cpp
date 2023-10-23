#include "ghost.h"

ghost::ghost()
{

}

void ghost::cut_sprites_color(QString name, QString color)

{
    QPixmap image;
    image.load(name);
    if(color == "red") {
        for(int i = 0; i < sprites_weight*8; i += sprites_weight) {
            sprites_color.push_back(image.copy(i, 2*sprites_height, sprites_weight, sprites_height));
        }
        setPixmap(sprites_color[0]);
    }
    if(color == "pink") {
        for(int i = 0; i < sprites_weight*8; i += sprites_weight) {
            sprites_color.push_back(image.copy(i, 3*sprites_height, sprites_weight, sprites_height));
        }
        setPixmap(sprites_color[0]);
    }
    if(color == "cian") {
        for(int i = 0; i < sprites_weight*8; i += sprites_weight) {
            sprites_color.push_back(image.copy(i, 4*sprites_height, sprites_weight, sprites_height));
        }
        setPixmap(sprites_color[0]);
    }
    if(color == "yellow") {
        for(int i = 0; i < sprites_weight*8; i += sprites_weight) {
            sprites_color.push_back(image.copy(i, 5*sprites_height, sprites_weight, sprites_height));
        }
        setPixmap(sprites_color[0]);
    }
}

void ghost::cut_sprites_azules(QString name)
{
    QPixmap image;
    image.load(name);
    for(int i = 0; i < sprites_weight*4; i += sprites_weight) {
        sprites_azules.push_back(image.copy(i, 7*sprites_height, sprites_weight, sprites_height));
    }
    setPixmap(sprites_azules[0]);
}

void ghost::cut_sprites_ojos(QString name)
{
    QPixmap image;
    image.load(name);
    for(int i = 0; i < sprites_weight*4; i += 2*sprites_weight) {
        ojos.push_back(image.copy(i, 6*sprites_height, sprites_weight, sprites_height));
    }
    setPixmap(ojos[0]);
}

