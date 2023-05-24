#pragma once
#include <SFML/Graphics.hpp>
#include "pacman.h"
#include "food.h"
#include "wall.hpp"
#include "cenario.h"
#include "Ghost.h"
<<<<<<< HEAD
#include "portal.hpp"
=======
>>>>>>> 8d2823b0164ba5196cc18c056cfa0bab944862a7

const int window_width = 800;
const int window_height = 600;

class Game
{
private:
    sf::RenderWindow *window;

    Pacman *pacman;
    Pacman *pacman2;

    Ghost *ghosts[4];

    std::vector<Portal*> portais;

    Ghost *ghosts[4];

    std::vector<Food*> foods;
    std::vector<Wall*> bricks;

public:
    Game();
    ~Game();
    void inicializar(sf::RenderWindow *w);
    void processarEntrada(sf::Event *event, float tempo);
    void atualizar(float tempo);
    void renderizar();
    void finalizar();
};
