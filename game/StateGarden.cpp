/**
Peach Game By
Lucas Ranzi, Lorenzo Manica e Rafael Julião
 */
#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>

#include "Game.h"
#include "StateGarden.h"
#include "InputManager.h"


StateGarden StateGarden::m_StateGarden;

using namespace std;

void StateGarden::init()
{
    //Load Map
    map = new tmx::MapLoader("data/maps");
    map->Load("garden.tmx");

    player = new Player();
    sf::Vector2u tilesize = map->GetMapTileSize();
    player->setPosition(tilesize.x * 8, tilesize.y * 2);

    //Configure Controls Mapping
    im = cgf::InputManager::instance();
    im->addKeyInput("left", sf::Keyboard::Left);
    im->addKeyInput("right", sf::Keyboard::Right);
    im->addKeyInput("up", sf::Keyboard::Up);
    im->addKeyInput("down", sf::Keyboard::Down);
    im->addKeyInput("quit", sf::Keyboard::Escape);
    im->addKeyInput("stats", sf::Keyboard::S);
    im->addKeyInput("space", sf::Keyboard::Space);
    im->addMouseInput("rightclick", sf::Mouse::Right);

    cout << "StateGarden: Init" << endl;
}



void StateGarden::handleEvents(cgf::Game* game)
{
    screen = game->getScreen();
    sf::View view = screen->getView();
    sf::Event event;

    while (screen->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            game->quit();
    }

    //Player Control Events
    player->control(im);

    //Generic Control Events
    if(im->testEvent("quit") || im->testEvent("rightclick"))
        game->quit();

    if(im->testEvent("stats"))
        game->toggleStats();


}

void StateGarden::update(cgf::Game* game)
{
    //Get Window
    screen = game->getScreen();

    //Center Window on Player
    centerMapOnPlayer();
}



void StateGarden::draw(cgf::Game* game)
{
    screen = game->getScreen();
    map->Draw(*screen);
    screen->draw(*player);

}



void StateGarden::cleanup()
{
    delete map;
    cout << "StateGarden: Clean" << endl;
}

void StateGarden::pause()
{
    cout << "StateGarden: Paused" << endl;
}

void StateGarden::resume()
{
    cout << "StateGarden: Resumed" << endl;
}



// Centers the camera on the player position
void StateGarden::centerMapOnPlayer()
{
    sf::View view = screen->getView();
    sf::Vector2u mapsize = map->GetMapSize();
    sf::Vector2f viewsize = view.getSize();
    viewsize.x /= 2;
    viewsize.y /= 2;
    sf::Vector2f pos = player->getPosition();

    float panX = viewsize.x; // minimum pan
    if(pos.x >= viewsize.x)
        panX = pos.x;

    if(panX >= mapsize.x - viewsize.x)
        panX = mapsize.x - viewsize.x;

    float panY = viewsize.y; // minimum pan
    if(pos.y >= viewsize.y)
        panY = pos.y;

    if(panY >= mapsize.y - viewsize.y)
        panY = mapsize.y - viewsize.y;

    sf::Vector2f center(panX,panY);
    view.setCenter(center);

    screen->setView(view);
}

