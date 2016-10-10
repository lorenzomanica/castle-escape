/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */
#include "Player.h"

Player::Player(){
    //Initiate Walk states
    walkStates[0] = "walk-right";
    walkStates[1] = "walk-left";
    walkStates[2] = "walk-up";
    walkStates[3] = "walk-down";

    //Initiate Directions Variables
    dirx = 0; // x => right (1), left (-1)
    diry = 0; // y => down (1), up (-1)
    currentDir = RIGHT;

    setPosition(40,100);

    load("data/img/peach.png",
        28,52,
        36,12,
        16,12,
        13,21,273);

    loadAnimation("data/img/peach.xml");
    setAnimation(walkStates[currentDir]);

    setAnimRate(30);
    setScale(1,1);
    play();
}


void Player::control(cgf::InputManager*  input){


    dirx = diry = 0;
    int newDir = currentDir;
    bool dash = input->testEvent("space");

    if(input->testEvent("left")) {
        dirx = -1;
        newDir = LEFT;
    }

    if(input->testEvent("right")) {
        dirx = 1;
        newDir = RIGHT;
    }

    if(input->testEvent("up")) {
        diry = -1;
        newDir = UP;
    }

    if(input->testEvent("down")) {
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
        setAnimRate(60);
        setXspeed( DASH_SPEED * dirx);
        setYspeed( DASH_SPEED * diry);
    }else{
        setAnimRate(30);
        setXspeed( NORMAL_SPEED * dirx);
        setYspeed( NORMAL_SPEED * diry);
    }

}
