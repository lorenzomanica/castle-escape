/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */
#include "Enemy.h"

Enemy::Enemy()
{
    //Initiate Walk states
    walkStates[0] = "walk-right";
    walkStates[1] = "walk-left";
    walkStates[2] = "walk-up";
    walkStates[3] = "walk-down";

    //Initiate Directions Variables
    dirx = 0; // x => right (1), left (-1)
    diry = 0; // y => down (1), up (-1)
//    currentDir = RIGHT;

    setPosition(0,0);

    load("data/img/enemy.png",
        28,52,
        36,12,
        16,12,
        13,21,273);

//    loadAnimation("data/img/enemy.xml");
//    setAnimation(walkStates[currentDir]);

//    setAnimRate(30);
//    setScale(1,1);
//    play();
}

Enemy::Enemy(float x, float y, int mov, float minx, float miny, float maxx, float maxy) {
    //Initiate Walk states
    walkStates[0] = "walk-right";
    walkStates[1] = "walk-left";
    walkStates[2] = "walk-up";
    walkStates[3] = "walk-down";

    //Initiate Directions Variables
    dirx = 0; // x => right (1), left (-1)
    diry = 0; // y => down (1), up (-1)
    movement = mov;
    currentDir = RIGHT;

    this->minx = minx;
    this->miny = miny;
    this->maxx = maxx;
    this->maxy = maxy;

    setPosition(x,y);

    if (mov == HORIZONTAL_MOVE) {
        if ((x == maxx)) currentDir = LEFT;
        else currentDir = RIGHT;
    }
    if (mov == VERTICAL_MOVE) {
        if ((y == maxy)) currentDir = UP;
        else currentDir = DOWN;
    }

    load("data/img/enemy.png",
        28,52,
        36,12,
        16,12,
        13,21,273);

    loadAnimation("data/img/enemy.xml");
    setAnimation(walkStates[currentDir]);

    setAnimRate(30);
    setScale(1,1);
    play();
}

void Enemy::updatePosition() {
    sf::Vector2f pos = getPosition();

    if (movement == HORIZONTAL_MOVE) {
        if (pos.x > maxx) {
            dirx = -3;
            currentDir = LEFT;
            setAnimation(walkStates[currentDir]);
        }
        else if (pos.x < minx) {
            dirx = 3;
            currentDir = RIGHT;
            setAnimation(walkStates[currentDir]);
        }
        else {
            if (currentDir == RIGHT)
                dirx = 3;
            else
                dirx = -3;
        }
    }

    if (movement == VERTICAL_MOVE) {
        if (pos.y > maxy) {
            diry = -3;
            currentDir = UP;
            setAnimation(walkStates[currentDir]);
        }
        else if (pos.y < miny) {
            diry = 3;
            currentDir = DOWN;
            setAnimation(walkStates[currentDir]);
        }
        else {
            if (currentDir == DOWN)
                diry = 3;
            else
                diry = -3;
        }
    }
    play();
    setPosition(pos.x+dirx, pos.y+diry);
}
