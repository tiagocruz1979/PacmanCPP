#pragma once
#include <SFML/Graphics.hpp>
#include "pacman.h"
#include "food.h"
#include "wall.hpp"
#include "cenario.h"
#include "Ghost.h"
#include "portal.hpp"
#include "door.hpp"
#include "key.hpp"
#include "painel.hpp"
#include "caixa.hpp"
#include "util.hpp"


const int window_width = 1024;
const int window_height = 600;

class Game
{
private:
    sf::RenderWindow *window;

    std::vector<Pacman*> pacman;
    std::vector<Ghost*> ghosts;
    std::vector<Portal*> portais;
    std::vector<sf::RectangleShape> portalDestino;
    std::vector<Food*> foods;
    std::vector<Wall*> bricks;
    std::vector<Door*> doors;
    std::vector<Key*> keys;
    std::vector<Painel*>paineis;
    std::vector<Caixa*>caixas;
    std::vector<std::vector<Wall*>> new_bricks;

public:
    Game();
    ~Game();
    void inicializar(sf::RenderWindow *w);
    void processarEntrada(sf::Event *event, float tempo);
    void atualizar(float tempo);
    void renderizar();
    void finalizar();

    sf::Texture imgPacman;
    sf::Sprite sptPacman;

    sf::Texture imgFundo;
    sf::Sprite sptFundo;
};
