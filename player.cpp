#include "player.h"

player::player(Compass *compass_ipt)
{
    cut_sprites_alive(":/sprites/sprites.png");
    cut_sprites_dead(":/sprites/sprites.png");

    direction = QPoint(0, 0);
    tmpDir = QPoint(0, 0);

    setPixmap(sprites_alive[1]);

    switchTimer = new QTimer();
    switchTimer->start();
    connect(switchTimer, SIGNAL(timeout()), this, SLOT(switchAnimate()));
    switchTimer->setInterval(40);

    compass = compass_ipt;
    compass->setLoc(QPoint(0, 0), 'p');

    score = 0;
    index = 0;
    add = 1;
    isAlive = true;
}

void player::cut_sprites_alive(QString name)
{
    QPixmap image;
    image.load(name);

    sprites_alive.push_back(image.copy(0,0, sprites_weight, sprites_height));
    sprites_alive.push_back(image.copy(sprites_weight,0, sprites_weight, sprites_height));
    sprites_alive.push_back(image.copy(2*sprites_weight,0, sprites_weight, sprites_height));
}

void player::cut_sprites_dead(QString name)
{
    QPixmap image;
    image.load(name);

    for(int i = 0; i < sprites_weight*11; i += sprites_weight) {
        sprites_dead.push_back(image.copy(i, 1*sprites_height, sprites_weight, sprites_height));
    }
}

void player::addScore(int value)
{
    score += value;
}

void player::setDirection(QPoint dir)
{
    if(isAlive)
    {
        if (x() == 216 && y() == 403 && direction == QPoint(0, 0) && (dir == Left || dir == Right)) { //spawn
            if (dir == Left) {
                setTransformOriginPoint(sprites_weight/2, sprites_height/2);
                setRotation(180);
            }
            else if (dir == Right) {
                setTransformOriginPoint(sprites_weight/2, sprites_height/2);
                setRotation(0);
            }
        }
        tmpDir = dir;
    }

}

void player::setScore(unsigned long newScore)
{
    score = newScore;
}

unsigned long player::getScore()
{
    return score;
}

void player::move() {

    compass->setPos(pos());
    if(isAlive)
    {
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
            setPos(pos() + direction * 2);

            if (x() < -30)
                setX(478);
            else if (x() > 478)
                setX(-30);
        }
        // movimiento normal del pacman
        else if (int(y() - 35) % 16 == 0 && int(x()) % 16 == 0) {

            compass->setLoc(QPoint(int(y()-35) / 16, int(x()) / 16), 'a');
            if (tmpDir != direction && compass->canMove(pos(), tmpDir)) {
                direction = tmpDir;
                if (direction == Up)
                {
                    setTransformOriginPoint(sprites_weight/2, sprites_height/2);
                    setRotation(270);
                }
                else if (direction == Down)
                {
                    setTransformOriginPoint(sprites_weight/2, sprites_height/2);
                    setRotation(90);
                }
                else if (direction == Left)
                {
                    setTransformOriginPoint(sprites_weight/2, sprites_height/2);
                    setRotation(180);
                }
                else if (direction == Right)
                {
                    setTransformOriginPoint(sprites_weight/2, sprites_height/2);
                    setRotation(0);
                }
            }
            else if (compass->canMove(pos(), direction)) {
                compass->check(pos(), direction);
                setPos(pos() + direction*2);
                switchTimer->start();
            }
            else {
                compass->check(pos(), direction);
                switchTimer->start();
                setPixmap(sprites_alive[1]);
            }
        }
        else
          setPos(pos() + direction*2);
    }
}

void player::switchAnimate() {

    if (isAlive) {
        setPixmap(sprites_alive[index]);
        index += add;
        if (index >= 2 || index <= 0)
            add = -add;
    }
    else {
        if (index < 11) {
            setPixmap(sprites_dead[index]);
            index += add;
        }
        else if (index >= 11) {
            switchTimer->stop();
            add = 0;
            //isAlive = true;
            hide();
        }
    }
}

void player::die()
{
    isAlive = false;
    index = 0;
    add = 1;
}

player::~player()
{

}


