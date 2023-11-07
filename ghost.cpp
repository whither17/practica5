#include "ghost.h"

ghost::ghost(QString name, Compass *compass_ipt): compass(compass_ipt)
{
    setOffset(QPoint(-8, -8));
    tmpDir = QPoint(-1, -1);
    direction = QPointF(1, 0);

    if(name == "red") cut_sprites_color(":/sprites/sprites.png", "red");
    if(name == "pink") cut_sprites_color(":/sprites/sprites.png", "pink");
    if(name == "cian") cut_sprites_color(":/sprites/sprites.png", "cian");
    if(name == "yellow") cut_sprites_color(":/sprites/sprites.png", "yellow");

    cut_sprites_azules(":/sprites/sprites.png");
    cut_sprites_ojos(":/sprites/sprites.png");

    switchTimer = new QTimer();
    nerfTimer = new QTimer();

    connect(switchTimer, SIGNAL(timeout()), this, SLOT(switchAnimate()));
    connect(compass, SIGNAL(powerUp()), this, SLOT(nerfInterval()));
    switchTimer->start(80);
    index_i = 1;
    index_j = 0;

    nerf = false;
    home = false;
    isAlive = true;
    remainNerf = 0;
}

void ghost::cut_sprites_color(QString name, QString color)

{
    QPixmap image;
    image.load(name);
    if(color == "red") {
        for(int i = 0; i < sprites_weight*8; i += sprites_weight) {
            sprites_color.push_back(image.copy(i, 2*sprites_height, sprites_weight, sprites_height));
        }
    }
    if(color == "pink") {
        for(int i = 0; i < sprites_weight*8; i += sprites_weight) {
            sprites_color.push_back(image.copy(i, 3*sprites_height, sprites_weight, sprites_height));
        }
    }
    if(color == "cian") {
        for(int i = 0; i < sprites_weight*8; i += sprites_weight) {
            sprites_color.push_back(image.copy(i, 4*sprites_height, sprites_weight, sprites_height));
        }
    }
    if(color == "yellow") {
        for(int i = 0; i < sprites_weight*8; i += sprites_weight) {
            sprites_color.push_back(image.copy(i, 5*sprites_height, sprites_weight, sprites_height));
        }
    }
}

void ghost::cut_sprites_azules(QString name)
{
    QPixmap image;
    image.load(name);
    for(int i = 0; i < sprites_weight*4; i += sprites_weight) {
        sprites_azules.push_back(image.copy(i, 7*sprites_height, sprites_weight, sprites_height));
    }  
}

void ghost::cut_sprites_ojos(QString name)
{
    QPixmap image;
    image.load(name);
    for(int i = 0; i < sprites_weight*8; i += 2*sprites_weight) {
        ojos.push_back(image.copy(i, 6*sprites_height, sprites_weight, sprites_height));
    }
}

void ghost::move()
{
    if(compass->canMove(pos(), direction))
        setPos(pos() + direction *1);
}

void ghost::switchAnimate()
{
    if (!nerf) {
        if (direction == Dir::Up)
        {
            index_o = 3;
            index_i = 6;
        }
        else if (direction == Dir::Down)
        {
            index_o = 1;
            index_i = 2;
        }
        else if (direction == Dir::Left)
        {
            index_o = 2;
            index_i = 4;
        }
        else
        {
            index_o = 0;
            index_i = 0;
        }

        if (!isAlive)
            setPixmap(ojos[2]);
        else
            setPixmap(sprites_color[index_i + index_j]);
    }
    else
        setPixmap(sprites_azules[0 + index_j]);

    index_j ++;
    if (index_j >= 2)
        index_j = 0;
}

void ghost::nerfInterval()
{

    nerf = true;
}

ghost::~ghost()
{
    delete nerfTimer;
    delete switchTimer;
}


