#include "game.h"
#include <iostream>


void Game::finalizar()
{
    delete this->window;
}

void Game::inicializar(sf::RenderWindow *w)
{
    this->window = w;

    Pacman *p1 = new Pacman();
    p1->setPosition(550.f,430.f);
    p1->memorizaPosicao();
    p1->setColor(sf::Color::Blue);
    p1->setControles(sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Right,sf::Keyboard::Left,sf::Keyboard::Num0);
    this->pacman.push_back(p1);

    Pacman *p2 = new Pacman();
    p2->setPosition(10.f,60.f);
    p2->setColor(sf::Color::Red);
    p2->memorizaPosicao();
    p2->setControles(sf::Keyboard::W,sf::Keyboard::S,sf::Keyboard::D,sf::Keyboard::A,sf::Keyboard::Z);
    this->pacman.push_back(p2);

    int idxCenario = 0;
    int idxPortal = 0;
    std::vector<std::string> &cen = getCenario(idxCenario);

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
                //std::cout << "Criando portal \n";
                Portal *p1 = new Portal();
                p1->setColor(sf::Color(100,50,50,255));
                p1->setPosition(i*10.f,j*10.f);
                p1->setPosTransportation(getDestinoPortal(idxCenario,idxPortal));

                sf::RectangleShape pd;
                pd.setPosition(p1->getDestino());
                pd.setFillColor(sf::Color(150,150,50,200));
                pd.setSize(sf::Vector2f(40.f,40.f));

                idxPortal++;

                this->portalDestino.push_back(pd);
                this->portais.push_back(p1);
            }
            else if(c=='g') // criando os fantasmas
            {
                Ghost *g = new Ghost();
                g->setPosition(j*10.f,i*10.f);
                this->ghosts.push_back(g);
            }
            else if(c=='d') // porta vertical
            {
                Door *d = new Door(1001,j*10.f,i*10.f,40.f,10.f);
                this->doors.push_back(d);
            }
            else if(c=='D') // porta horizontal
            {
                Door *d = new Door(1001,j*10.f,i*10.f,10.f,40.f);
                this->doors.push_back(d);
            }
            else if(c=='k') // chave
            {
                Key *k = new Key(1001,j*10.f,i*10.f,20.f,10.f);
                this->keys.push_back(k);
            }
        }
    }

}

void Game::processarEntrada(sf::Event *event, float tempo)
{

    for(Pacman *p : this->pacman)
    {
        p->memorizaPosicao();
        p->comandos(tempo);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L)) // soltar
        {
            std::cout << "Tentando soltar a chave\n";
            Key *k = p->soltarChave();
            if(k!=nullptr)
            {
                std::cout << "existe a chave\n";
                this->keys.push_back(k);
                p->setChave(nullptr);
                break;
            }
        }
    }

    for(Ghost *g : this->ghosts)
    {
        g->memorizarPosicao();
        g->mov(0.5);
    }




    //colisoes

    //colisão com parede
    int vSize = 0;
    vSize = static_cast<int>(this->bricks.size());
    for(int i =0; i < vSize ;i++)
    {
        for(int p = 0 ; p < 2 ;p++)
        {
            if(this->bricks.at(i)->getShape().getGlobalBounds().intersects(this->pacman.at(p)->getShape().getGlobalBounds()))
            {
                this->pacman.at(p)->restauraPosicaoValida();
            }
        }

        for(Ghost *g : this->ghosts)
        {
            if(g->colision(this->bricks.at(i)->getShape()))
            {
                g->restaurarPosicao();
                g->girarRandom();
            }
        }
    }

    // colisão com portal
    vSize = static_cast<int>(this->portais.size());
    for(int i = 0 ; i < vSize ;i++)
    {
        for(int p = 0 ; p < 2 ;p++)
        {
            if(this->portais.at(i)->getShape().getGlobalBounds().intersects(this->pacman.at(p)->getShape().getGlobalBounds()))
            {
                this->pacman.at(p)->setPosition(this->portais.at(i)->getDestino().x, this->portais.at(i)->getDestino().y);
                this->portais.at(i)->som();
            }
        }

        int n = this->ghosts.size();
        for(int j = 0 ; j < n ; j++)
        {
            if(this->ghosts.at(j)->colision(this->portais.at(i)->getShape()))
            {
               this->ghosts.at(j)->setPosition(this->portais.at(i)->getDestino().x,this->portais.at(i)->getDestino().y);
            }
        }
    }

    // colisão com comida
    vSize = static_cast<int>(this->foods.size());
    int idelete = -1;
    for(int i =0; i < vSize ;i++)
    {
        for(int p = 0 ; p < 2 ;p++)
        {
            if(this->foods.at(i)->getShape().getGlobalBounds().intersects(this->pacman.at(p)->getShape().getGlobalBounds()))
            {
                idelete = i;
                this->pacman.at(p)->comer();
            }
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
        for(int p = 0 ; p < 2 ; p++)
        {
            if(this->ghosts.at(i)->colision(this->pacman.at(p)->getShape()))
            {
                this->pacman.at(p)->morre();
            }
        }
    }



        //colisao com chave
        vSize = static_cast<int>(this->keys.size());
        idelete = -1;
        for(int i = 0 ; i < vSize ;i++)
        {
            for(Pacman *p: this->pacman)
            {
                if(p->getShape().getGlobalBounds().intersects(this->keys.at(i)->getShape().getGlobalBounds()))
                {
                    if(p->pegarChave(this->keys.at(i)))
                    {
                        //this->keys.erase(this->keys.begin()+i);
                        idelete = i;
                        break;
                    }
                }
            }
         }
         if(idelete>=0) this->keys.erase(this->keys.begin()+idelete);


        vSize = static_cast<int>(this->doors.size());
        idelete=-1;
        for(int i = 0 ; i < vSize ;i++)
        {
            for(Pacman *p : this->pacman)
            {
                if(p->getShape().getGlobalBounds().intersects(this->doors.at(i)->getShape().getGlobalBounds()))
                {
                    if(p->getChave() != nullptr && p->getChave()->getSegredo()==this->doors.at(i)->getSegredo())
                    {
                        this->doors.at(i)->som();
                        std::cout << "porta aberta\n";
                        idelete = i;
                        p->setChave(nullptr);
                        //this->doors.erase(this->doors.begin()+i);
                        break;
                    }
                    else
                    {
                        std::cout << "Tipo incorreto da chave\n";
                        p->restauraPosicaoValida();
                    }
                }
            }
        }
        if(idelete>=0) this->doors.erase(this->doors.begin()+idelete);

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
    vSize = static_cast<int>(this->portalDestino.size());
    for(int i = 0 ; i < vSize ;i++)
    {
        this->window->draw(portalDestino.at(i));
    }


    int nGhosts = this->ghosts.size();
    for(int i = 0 ; i < nGhosts;i++)
    {
        this->ghosts.at(i)->draw(this->window);
    }

    int nDoors = this->doors.size();
    for(int i = 0 ; i < nDoors;i++)
    {
        this->doors.at(i)->draw(this->window);
    }

    int nKeys = this->keys.size();
    for(int i = 0 ; i < nKeys;i++)
    {
        this->keys.at(i)->draw(this->window);
    }

    for(Pacman *p : this->pacman)
    {
        p->draw(this->window);
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

    n = this->ghosts.size();
    for(int i = 0 ; i < n;i++)
    {
        delete this->ghosts.at(i);
        this->ghosts.pop_back();
    }

    n = this->doors.size();
    for(int i = 0 ; i < n ; i++)
    {
        delete this->doors.at(i);
        this->doors.pop_back();
    }

    n = this->pacman.size();
    for(int i = 0 ; i < n ; i++)
    {
        delete this->pacman.at(i);
        this->pacman.pop_back();
    }

}



