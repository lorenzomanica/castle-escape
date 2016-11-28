/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */

#ifndef GARDEN_STATE_H_
#define GARDEN_STATE_H_

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"
#include <tmx/MapLoader.h>
#include <string>
#include "Player.h"

class StateGarden : public cgf::GameState
{
    public:

    void init();
    void cleanup();

    void pause();
    void resume();

    void handleEvents(cgf::Game* game);
    void update(cgf::Game* game);
    void draw(cgf::Game* game);

    // Implement Singleton Pattern
    static StateGarden* instance()
    {
        return &m_StateGarden;
    }

    protected:
    StateGarden() {}


    private:

    //Singleton
    static StateGarden m_StateGarden;

    //Player
    Player * player;

    //Map Loader
    tmx::MapLoader* map;

    //Window Managment
    sf::RenderWindow* screen;
    cgf::InputManager* im;


    //Helper Methods
    void centerMapOnPlayer();

};

#endif
