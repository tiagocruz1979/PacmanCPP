#include "game.h"
#include <iostream>

void Game::finalizar()
{
    delete this->window;
}

void Game::inicializar(sf::RenderWindow *w)
{
    this->window = w;

    pacman = new Pacman();
    pacman->setPosition(20.f,20.f);
    pacman->memorizaPosicao();

    std::vector<std::string> &cen = getCenario(0);
    int linhas = cen.size();
    for(int i = 0 ; i < linhas; i++)
    {
        int colunas = cen.at(i).size();
        for(int j = 0 ; j < colunas ; j++)
        {
            char c = cen.at(i).at(j);
            if(c=='f')
            {
                this->foods.push_back(new Food(j*10.f,i*10.f));
            }
            else if (c=='p')
            {
                this->bricks.push_back(new Wall(j*10.f, i*10.f));
            }
        }
    }

}

void Game::processarEntrada(sf::Event *event, float tempo)
{

    this->pacman->memorizaPosicao();

    if(event->type == sf::Event::KeyPressed)
    {
        if(event->key.code == sf::Keyboard::Key::Up) // seta para cima
        {
            this->pacman->setDirecao(3);
            this->pacman->mov(tempo);
        }

        if(event->key.code == sf::Keyboard::Key::Down) // seta para Baixo
        {
            this->pacman->setDirecao(1);
            this->pacman->mov(tempo);
        }
        if(event->key.code == sf::Keyboard::Key::Left) // seta para Esquerda
        {
            this->pacman->setDirecao(2);
            this->pacman->mov(tempo);
        }

        if(event->key.code == sf::Keyboard::Key::Right) // seta para Direita
        {
            this->pacman->setDirecao(0);
            this->pacman->mov(tempo);
        }
    }

    //colisoes
    int vSize = 0;
    vSize = static_cast<int>(this->bricks.size());
    for(int i =0; i < vSize ;i++)
    {
        if(this->bricks.at(i)->getShape().getGlobalBounds().intersects(this->pacman->getShape().getGlobalBounds()))
        {
            this->pacman->restauraPosicaoValida();
        }
    }

    vSize = static_cast<int>(this->foods.size());
    int idelete = -1;
    for(int i =0; i < vSize ;i++)
    {
        if(this->foods.at(i)->getShape().getGlobalBounds().intersects(this->pacman->getShape().getGlobalBounds()))
        {
            idelete = i;
        }
    }
    if(idelete>=0)
    {
        Food *itemDeletar = this->foods.at(idelete);
        this->foods.erase(this->foods.begin()+idelete);
        delete itemDeletar;
    }

}

void Game::atualizar(float tempo)
{

}

void Game::renderizar()
{
    this->pacman->draw(this->window);

    int vSize = 0;

    vSize = static_cast<int>(this->foods.size());
    for(int i = 0 ; i < vSize ;i++)
    {
        this->foods.at(i)->draw(this->window);
    }
    vSize = static_cast<int>(this->bricks.size());
    for(int i = 0 ; i < vSize ;i++)
    {
        this->bricks.at(i)->draw(this->window);
    }

}

Game::Game()
{

}

Game::~Game()
{
    int n = this->foods.size();
    for(int i = 0 ; i < n;i++)
    {
        delete this->foods.at(i);
        this->foods.pop_back();
    }
}


