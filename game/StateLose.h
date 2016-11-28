/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */

#ifndef LOSE_STATE_H_
#define LOSE_STATE_H_

#include "GameState.h"
#include <string>

class StateLose : public cgf::GameState
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
    static StateLose* instance()
    {
        return &m_StateLose;
    }

    protected:
    StateLose() {}


    private:

    //Singleton
    static StateLose m_StateLose;


    sf::Font font;
    sf::Text text;


    //Window Managment
    sf::RenderWindow* screen;

};

#endif
