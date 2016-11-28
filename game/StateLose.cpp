/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */
#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>

#include "Game.h"
#include "StateLose.h"


StateLose StateLose::m_StateLose;

using namespace std;

void StateLose::init()
{

    //Load Font
    if (!font.loadFromFile("data/fonts/arial.ttf")) {
        cout << "Cannot load arial.ttf font!" << endl;
        exit(1);
    }
    text.setFont(font);
    text.setCharacterSize(24); // in pixels
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(150,150);
    text.setString("L is for Loser");
    cout << "StateLose: Init" << endl;
}



void StateLose::handleEvents(cgf::Game* game)
{


}

void StateLose::update(cgf::Game* game)
{


}

void StateLose::draw(cgf::Game* game)
{
    screen = game->getScreen();
    screen->draw(text);
}



void StateLose::cleanup()
{
    cout << "StateLose: Clean" << endl;
}

void StateLose::pause()
{
    cout << "StateLose: Paused" << endl;
}

void StateLose::resume()
{
    cout << "StateLose: Resumed" << endl;
}
