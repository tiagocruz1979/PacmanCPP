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

    pacman2 = new Pacman();
    pacman2->setPosition(20.f,20.f);
    pacman2->setColor(sf::Color::Cyan);
    pacman2->memorizaPosicao();

    for(int i = 0 ; i < 4 ;i++)
    {
      this->ghosts[i] = new Ghost();
      this->ghosts[i]->setPosition(250.f+i*50.f,240.f);
    }
    this->ghosts[0]->setColor(sf::Color::Cyan);
    this->ghosts[1]->setColor(sf::Color::White);
    this->ghosts[2]->setColor(sf::Color::Magenta);
    this->ghosts[3]->setColor(sf::Color::Green);



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
            else if(c=='t') // portal de transporte
            {
                std::cout << "Criando portal \n";
                Portal *p1 = new Portal();
                p1->setColor(sf::Color::Blue);
                p1->setPosition(i*10.f,j*10.f);
                p1->setPosTransportation(20.f,20.f);
                this->portais.push_back(p1);
            }
        }
    }

    if (this->portais.size()>0) this->portais.at(0)->setPosTransportation(600.f,250.f);
    if (this->portais.size()>1) this->portais.at(1)->setPosTransportation(20.f,20.f);



}

void Game::processarEntrada(sf::Event *event, float tempo)
{

    this->pacman->memorizaPosicao();
    this->pacman2->memorizaPosicao();

   // if(event->type == sf::Event::KeyPressed)
   // {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // seta para cima
        {
            this->pacman->setDirecao(3);
            this->pacman->mov(tempo);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // seta para Baixo
        {
            this->pacman->setDirecao(1);
            this->pacman->mov(tempo);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // seta para Esquerda
        {
            this->pacman->setDirecao(2);
            this->pacman->mov(tempo);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // seta para Direita
        {
            this->pacman->setDirecao(0);
            this->pacman->mov(tempo);
        }
   // }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))// seta para cima
        {
            this->pacman2->setDirecao(3);
            this->pacman2->mov(tempo);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // seta para Baixo
        {
            this->pacman2->setDirecao(1);
            this->pacman2->mov(tempo);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // seta para Esquerda
        {
            this->pacman2->setDirecao(2);
            this->pacman2->mov(tempo);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // seta para Direita
        {
            this->pacman2->setDirecao(0);
            this->pacman2->mov(tempo);
        }


    //colisoes

    //colisão com parede
    int vSize = 0;
    vSize = static_cast<int>(this->bricks.size());
    for(int i =0; i < vSize ;i++)
    {
        if(this->bricks.at(i)->getShape().getGlobalBounds().intersects(this->pacman->getShape().getGlobalBounds()))
        {
            this->pacman->restauraPosicaoValida();
        }
        if(this->bricks.at(i)->getShape().getGlobalBounds().intersects(this->pacman2->getShape().getGlobalBounds()))
        {
            this->pacman2->restauraPosicaoValida();
        }
    }

    // colisão com portal
    vSize = static_cast<int>(this->portais.size());
    for(int i = 0 ; i < vSize ;i++)
    {
        if(this->portais.at(i)->getShape().getGlobalBounds().intersects(this->pacman->getShape().getGlobalBounds()))
        {
            this->pacman->setPosition(this->portais.at(i)->getDestino().x, this->portais.at(i)->getDestino().y);
        }
        if(this->portais.at(i)->getShape().getGlobalBounds().intersects(this->pacman2->getShape().getGlobalBounds()))
        {
            this->pacman2->setPosition(this->portais.at(i)->getDestino().x, this->portais.at(i)->getDestino().y);
        }
    }

    // colisão com comida
    vSize = static_cast<int>(this->foods.size());
    int idelete = -1;
    for(int i =0; i < vSize ;i++)
    {
        if(this->foods.at(i)->getShape().getGlobalBounds().intersects(this->pacman->getShape().getGlobalBounds()))
        {
            idelete = i;
            this->pacman->comer();
        }
        if(this->foods.at(i)->getShape().getGlobalBounds().intersects(this->pacman2->getShape().getGlobalBounds()))
        {
            idelete = i;
            this->pacman2->comer();
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

    vSize = static_cast<int>(this->portais.size());
    for(int i = 0 ; i < vSize ;i++)
    {
        this->portais.at(i)->draw(this->window);
    }

    this->pacman->draw(this->window);
    this->pacman2->draw(this->window);

    for(int i = 0 ; i < 4;i++)
    {
        this->ghosts[i]->draw(this->window);
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

    for(int i = 0 ; i < 4 ; i++)
    {
        delete this->ghosts[i];
    }
    delete [] this->ghosts;

    delete this->pacman;
    delete this->pacman2;
}


