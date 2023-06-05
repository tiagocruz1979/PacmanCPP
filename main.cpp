#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include "game.h"


int main()
{

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "PacmanCPP");
    //window.setFramerateLimit(60);


    Game *game = new Game();
    game->inicializar(&window);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game->processarEntrada(&event,1.0);

        game->atualizar(0.0);

        window.clear();

        game->renderizar();

        window.display();

    } //while do window

    game->finalizar();
    delete game;


    return 0;
}

