/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */
#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>

#include "Game.h"
#include "StatePreCastle.h"
#include "StateCastle.h"


StatePreCastle StatePreCastle::m_StatePreCastle;

using namespace std;

void StatePreCastle::init()
{

    //Load Font
    if (!font.loadFromFile("data/fonts/freepixel.ttf")) {
        cout << "Cannot load freepixel.ttf font!" << endl;
        exit(1);
    }

    start = time(0);

    image.load("data/img/peach_bowser.png");
    image.setScale(0.5,0.5);
    image.setPosition(200,150);
    STATE = 0;

    //Load Music
    music.openFromFile("data/audio/funebre_march.ogg");
    music.setVolume(50);  // 30% do volume máximo
    music.setLoop(true);  // modo de loop: repete continuamente.
    music.play();

    //Configure Controls Mapping
    im = cgf::InputManager::instance();
    im->addKeyInput("right", sf::Keyboard::Right);
    im->addKeyInput("space", sf::Keyboard::Space);

    text.setFont(font);
    text.setCharacterSize(16); // in pixels
    text.setColor(sf::Color::White);
    text.setPosition(220,360);

    text.setString("Princess Peach was kidnapped by the evil\nvilain named Bowser!");
    cout << "StatePreCastle: Init" << endl;
}



void StatePreCastle::handleEvents(cgf::Game* game)
{
    screen = game->getScreen();
    sf::View view = screen->getView();
    sf::Event event;

    while (screen->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            game->quit();
    }

    if(im->testEvent("space")){
        music.stop();
        game->changeState(StateCastle::instance());
    }

}

void StatePreCastle::update(cgf::Game* game)
{
    screen = game->getScreen();
    if( difftime(time(0), start) > SCENE_TIME_SECONDS && STATE == 0){
        STATE = 1;
        image.load("data/img/kidnapped_peach.png");
        text.setString("She was kept prisioner in Bowser's giant\n and cold castle for 30 years.");
    }
    if( difftime(time(0), start) > (2*SCENE_TIME_SECONDS) && STATE == 1 ){
        STATE = 2;
        image.load("data/img/mario_dead.png");
        text.setString("After several atemps Mario end up dead.\nNow Peach need to escape by herself!\nPress SPACE to start");
    }
}

void StatePreCastle::draw(cgf::Game* game)
{
    screen = game->getScreen();
    screen->draw(image);
    screen->draw(text);
}



void StatePreCastle::cleanup()
{
    cout << "StatePreCastle: Clean" << endl;
}

void StatePreCastle::pause()
{
    cout << "StatePreCastle: Paused" << endl;
}

void StatePreCastle::resume()
{
    cout << "StatePreCastle: Resumed" << endl;
}
