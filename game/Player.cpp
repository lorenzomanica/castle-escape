/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */
#include "Player.h"

Player::Player(){
    walkStates[0] = "walk-right";
    walkStates[1] = "walk-left";
    walkStates[2] = "walk-up";
    walkStates[3] = "walk-down";

    dirx = 0; // sprite dir: right (1), left (-1)
    diry = 0; // down (1), up (-1)
    currentDir = RIGHT;

    setPosition(40,100);
    load("data/img/warrior.png",
        28,52,
        36,12,
        16,12,
        13,21,273);
    loadAnimation("data/img/warrioranim.xml");
    setAnimation(walkStates[currentDir]);
    setAnimRate(30);
    setScale(1,1);
    play();
}


void Player::walk(int direction, bool dash){
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
        pause();
    }
    else {
        if(currentDir != newDir) {
            setAnimation(walkStates[newDir]);
            currentDir = newDir;
        }
        play();
    }
    if( dash ){
        setXspeed(300*dirx);
        setYspeed(300*diry);
        setAnimRate(60);
    }else{
        setAnimRate(30);
        setXspeed(100*dirx);
        setYspeed(100*diry);
    }

}
