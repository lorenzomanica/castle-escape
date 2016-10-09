/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <Sprite.h>


class Player : public cgf::Sprite
{


    public:
    enum { RIGHT=0, LEFT, UP, DOWN };
    int dirx, diry;
    int x, y;
    int currentDir;

    void walk(int direction);

    Player();

    protected:

    private:
    std::string walkStates[4];
};

#endif // PLAYER_H
