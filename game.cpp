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

    for(int i = 0 ; i < 4 ; i++)
    {
        Ghost *g = new Ghost();
        g->setPosition(200.f+(50*i),240.f);
        g->setColor(g->gerarCor(i));
        this->ghosts.push_back(g);
    }

    int idxCenario = 0;
    std::vector<std::string> &cen = getCenario(idxCenario);
    std::vector<sf::Vector2f> pDestino = getDestinoPortal(idxCenario);
    int idxPortal = 0;

    std::cout << "teste\n";
    int tam = pDestino.size();
    for(int i = 0 ; i < tam ; i++)
    {
        std::cout << pDestino.at(i).x << "," << pDestino.at(i).y << '\n';
    }
    std::cout << "fim\n";

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
                p1->setPosTransportation(pDestino.at(idxPortal).x,pDestino.at(idxPortal).y);
                idxPortal++;
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

        int nGhosts = this->ghosts.size();
        for(int i = 0 ; i < nGhosts;i++)
        {
            this->ghosts.at(i)->memorizarPosicao();
            this->ghosts.at(i)->mov(0.5);
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

        for(int j = 0 ; j < nGhosts;j++)
        {
            if(this->ghosts.at(j)->colision(this->bricks.at(i)->getShape()))
            {
                this->ghosts.at(j)->restaurarPosicao();
                this->ghosts.at(j)->girarRandom();
            }
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

    //coliscao com fantastama
    vSize = static_cast<int>(this->ghosts.size());
    for(int i = 0 ; i < vSize;i++)
    {
        if(this->ghosts.at(i)->colision(this->pacman->getShape()))
        {
            this->pacman->morre();
        }
        if(this->ghosts.at(i)->colision(this->pacman2->getShape()))
        {
            this->pacman2->morre();
        }

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


    int nGhosts = this->ghosts.size();
    for(int i = 0 ; i < nGhosts;i++)
    {
        this->ghosts.at(i)->draw(this->window);
    }

    this->pacman->draw(this->window);
    this->pacman2->draw(this->window);



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

    n = this->ghosts.size();
    for(int i = 0 ; i < n;i++)
    {
        delete this->ghosts.at(i);
        this->ghosts.pop_back();
    }

    delete this->pacman;
    delete this->pacman2;
}



