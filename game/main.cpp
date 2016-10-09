/*
 * Exemplo de uso do framework de jogo
 *
 * Cria um jogo com 3 estados: "menu", "play" e "pause"
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#include "Game.h"
#include "PlayState.h"

int main(int argc, char **argv)
{
    cgf::Game game(5,30);

	game.init("Castle Escape: Peach on the run!",800,600,false);

    game.changeState(PlayState::instance());

    //Set Starter Zoom
    sf::RenderWindow* screen = game.getScreen();
    sf::View view = screen->getView();
    view.zoom(0.625);
    screen->setView(view);


	while(game.isRunning())
	{
		game.handleEvents();
		game.update();
		game.draw();
	}

	// cleanup the engine
	game.clean();

    return 0;
}
