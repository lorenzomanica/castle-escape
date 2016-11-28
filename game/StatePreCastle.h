/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */

#ifndef PRE_CASTLE_STATE_H_
#define PRE_CASTLE_STATE_H_

#define SCENE_TIME_SECONDS 5

#include "Sprite.h"
#include "InputManager.h"
#include "GameState.h"
#include <string>

class StatePreCastle : public cgf::GameState
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
    static StatePreCastle* instance()
    {
        return &m_StatePreCastle;
    }

    protected:
    StatePreCastle() {}


    private:

    //Singleton
    static StatePreCastle m_StatePreCastle;
    time_t start;
    int STATE;
    cgf::Sprite image;

    sf::Font font;
    sf::Text text;

    //Window Managment
    sf::RenderWindow* screen;
    cgf::InputManager* im;

};

#endif
