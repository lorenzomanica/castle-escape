/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */

#ifndef CASTLE_STATE_H_
#define CASTLE_STATE_H_

#define START_TIMEOUT 100
#define WALL_TILE 2

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"
#include <tmx/MapLoader.h>
#include <string>
#include "Player.h"



class StateCastle : public cgf::GameState
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
    static StateCastle* instance()
    {
        return &m_StateCastle;
    }

    protected:
    StateCastle() {}


    private:

    //Singleton
    static StateCastle m_StateCastle;

    //Player
    Player * player;

    //Map Loader
    tmx::MapLoader* map;

    //Winning Lader
    cgf::Sprite lader;

    //Timer Control
    time_t start, lastTimeChange;
    sf::Font font;
    sf::Text text;
    int timeLeft;

    //Music Player
    sf::Music music;

    //Window Managment
    sf::RenderWindow* screen;
    cgf::InputManager* im;


    //Helper Methods
    void centerMapOnPlayer();

    bool checkCollision(uint8_t layer, cgf::Game* game, cgf::Sprite* obj);

    sf::Uint16 getCellFromMap(uint8_t layernum, float x, float y);
};

#endif
