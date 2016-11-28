/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <Sprite.h>

#define HORIZONTAL_MOVE 0
#define VERTICAL_MOVE 1

class Enemy : public cgf::Sprite
{
    public:
    //Movement Vars
    enum { RIGHT=0, LEFT, UP, DOWN };
    int dirx, diry;
    int currentDir;

    void updatePosition();

    Enemy();
    Enemy(float x, float y, int mov, float minx, float miny, float maxx, float maxy);

    protected:

    private:
    std::string walkStates[4];

    float minx, maxx, miny, maxy;
    int movement;
};

#endif // ENEMY_H
