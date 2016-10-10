/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */

#ifndef PLAY_STATE_H_
#define PLAY_STATE_H_

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"
#include <tmx/MapLoader.h>
#include <string>
#include "Player.h"

#define START_TIMEOUT 90
#define WALL_TILE 2

class PlayState : public cgf::GameState
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
    static PlayState* instance()
    {
        return &m_PlayState;
    }

    protected:
    PlayState() {}


    private:

    //Singleton
    static PlayState m_PlayState;

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


    //Window Managment
    sf::RenderWindow* screen;
    cgf::InputManager* im;

    void endGameWinning();

    void endGameLosing();

    //Helper Methods
    void centerMapOnPlayer();

    bool checkCollision(uint8_t layer, cgf::Game* game, cgf::Sprite* obj);

    sf::Uint16 getCellFromMap(uint8_t layernum, float x, float y);
};

#endif
