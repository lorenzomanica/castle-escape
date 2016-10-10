/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <Sprite.h>
#include "InputManager.h"

#define NORMAL_SPEED 150
#define DASH_SPEED 300


class Player : public cgf::Sprite
{


    public:
    //Movement Vars
    enum { RIGHT=0, LEFT, UP, DOWN };
    int dirx, diry;
    int currentDir;

    void control(cgf::InputManager * manager);

    Player();

    protected:

    private:
    std::string walkStates[4];
};

#endif // PLAYER_H
