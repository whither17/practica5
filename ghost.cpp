#include "ghost.h"

ghost::ghost(QString name, Compass *compass_ipt, player *ply): compass(compass_ipt), ply(ply)
{
    tmpDir = QPoint(0, 0);
    direction = QPointF(-1, 0);

    if(name == "red") cut_sprites_color(":/sprites/sprites.png", "red");
    if(name == "pink") cut_sprites_color(":/sprites/sprites.png", "pink");
    if(name == "cian") cut_sprites_color(":/sprites/sprites.png", "cian");
    if(name == "yellow") cut_sprites_color(":/sprites/sprites.png", "yellow");

    cut_sprites_azules(":/sprites/sprites.png");
    cut_sprites_ojos(":/sprites/sprites.png");

    switchTimer = new QTimer();

    connect(switchTimer, SIGNAL(timeout()), this, SLOT(switchAnimate()));
    connect(compass, SIGNAL(powerUp()), this, SLOT(nerfInterval()));
    switchTimer->start(80);
    index_i = 1;
    index_j = 0;
    i = 0;

    nerf = false;
    isAlive = true;
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

void ghost::collidPacman()
{
    if(nerf == false) {
        if(collidesWithItem(ply))
            emit fail();
    }
    else
    {
        if(collidesWithItem(ply))
            kill();
    }
}

void ghost::move()
{
    collidPacman();


    if(i > 3)
    i = 0;

    QPoint dr[] = {Up, Down, Left, Right};

    if (y() == 259. && (x() < 0 || x() >= 448)) {
        if (tmpDir == Left || tmpDir == Right)
            direction = tmpDir;
        if (direction == Left)
        {
            setTransformOriginPoint(sprites_weight/2, sprites_height/2);
            setRotation(180);
        }
        else if (direction == Right)
        {
            setTransformOriginPoint(sprites_weight/2, sprites_height/2);
            setRotation(0);
        }
        setPos(pos() + direction);

        if (x() < -30)
            setX(478);
        else if (x() > 478)
            setX(-30);
    }

    else if(compass->canMove(pos(), direction))
        setPos(pos()+direction);
    else
    {
        direction = dr[i];
        i = rand()%4;
        qDebug() << i;
    }

}

void ghost::switchAnimate()
{
    if (!nerf) {
        if (direction == Up)
        {
            index_o = 3;
            index_i = 6;
        }
        else if (direction == Down)
        {
            index_o = 1;
            index_i = 2;
        }
        else if (direction == Left)
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

void ghost::kill()
{
    setPos(width_/2,259-47);
    nerf = false;
}


void ghost::nerfInterval()
{
    nerf = true;
}

ghost::~ghost()
{
    delete switchTimer;
}


