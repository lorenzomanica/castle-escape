/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */

#include "Player.h"


enum { RIGHT=0, LEFT, UP, DOWN };
std::string walkStates[4];
int currentDir;
int x, y;
int dirx, diry;


Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void move(int direction){
    dirx = diry = 0;
    int newDir = currentDir;

    if(direction == LEFT) {
        dirx = -1;
        newDir = LEFT;
    }

    if(direction == RIGHT) {
        dirx = 1;
        newDir = RIGHT;
    }

    if(direction == UP) {
        diry = -1;
        newDir = UP;
    }

    if(direction == DOWN) {
        diry = 1;
        newDir = DOWN;
    }

    if(dirx == 0 && diry == 0) {
        cgf::Sprite::pause();
    }
    else {
        if(currentDir != newDir) {
            cgf::Sprite::setAnimation(walkStates[newDir]);
            currentDir = newDir;
        }
        cgf::Sprite::play();
    }

    cgf::Sprite::setXspeed(100*dirx);
    cgf::Sprite::setYspeed(100*diry);
}
