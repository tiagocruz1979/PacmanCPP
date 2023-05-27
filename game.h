#pragma once
#include <SFML/Graphics.hpp>
#include "pacman.h"
#include "food.h"
#include "wall.hpp"
#include "cenario.h"
#include "Ghost.h"
#include "portal.hpp"


const int window_width = 800;
const int window_height = 600;

class Game
{
private:
    sf::RenderWindow *window;

    Pacman *pacman;
    Pacman *pacman2;

    std::vector<Ghost*> ghosts;
    std::vector<Portal*> portais;
    std::vector<sf::RectangleShape> portalDestino;
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
