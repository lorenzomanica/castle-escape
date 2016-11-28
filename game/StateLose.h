/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */

#ifndef LOSE_STATE_H_
#define LOSE_STATE_H_

#include "Sprite.h"
#include "GameState.h"
#include "InputManager.h"
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

    //Image
    cgf::Sprite image;

    //Text
    sf::Font font;
    sf::Text text;

    //Music Player
    sf::Music music;

    //Window Managment
    sf::RenderWindow* screen;
    cgf::InputManager* im;

};

#endif
