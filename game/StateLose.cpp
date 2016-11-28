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
#include "StateCastle.h"


StateLose StateLose::m_StateLose;

using namespace std;

void StateLose::init()
{
    //Load Image
    image.load("data/img/peach_dead.png");
    image.setScale(0.5,0.5);
    image.setPosition(0,275);

    //Load Music
    music.openFromFile("data/audio/funebre_march.ogg");
    music.setVolume(50);  // 30% do volume máximo
    music.setLoop(true);  // modo de loop: repete continuamente.
    music.play();

    //Load Font
    if (!font.loadFromFile("data/fonts/freepixel.ttf")) {
        cout << "Cannot load freepixel.ttf font!" << endl;
        exit(1);
    }

    //Setup Text
    text.setFont(font);
    text.setCharacterSize(25); // in pixels
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(50, 25 );

    //Configure Controls Mapping
    im = cgf::InputManager::instance();
    im->addKeyInput("space", sf::Keyboard::Space);
    im->addKeyInput("quit", sf::Keyboard::Escape);
    im->addMouseInput("rightclick", sf::Mouse::Right);
}



void StateLose::handleEvents(cgf::Game* game)
{
    screen = game->getScreen();
    sf::View view = screen->getView();
    sf::Event event;

    while (screen->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            game->quit();
    }

    //Restart game with SPACE
    if(im->testEvent("space") ){
        music.stop();
        game->changeState(StateCastle::instance());
    }

    if(im->testEvent("quit") || im->testEvent("rightclick"))
        game->quit();

}

void StateLose::update(cgf::Game* game)
{
    text.setString("Press SPACE to restart");
}

void StateLose::draw(cgf::Game* game)
{
    screen = game->getScreen();
    screen->draw(image);
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
