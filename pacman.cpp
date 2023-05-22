#include "pacman.h"
#include <iostream>
Pacman::Pacman()
{
   this->corpo = new sf::RectangleShape(sf::Vector2f(40.0,40.0));
   this->olho = new sf::RectangleShape(sf::Vector2f(5.0,5.0));
   this->corpo->setFillColor(sf::Color::Yellow);
   this->olho->setFillColor(sf::Color::Black);
   direcao = 0; // 0 = Direita , 1 = baixo , 2 = esquerda , 3 = cima
}

Pacman::~Pacman()
{
    //dtor
}

void Pacman::setDirecao(int d)
{
    this->direcao = d;
}

int Pacman::getDirecao()
{
    return this->direcao;
}

void Pacman::draw(sf::RenderWindow* w)
{
    w->draw(*corpo);
    w->draw(*olho);
}


void Pacman::mov(float v)
{

    int dir = getDirecao();

    if(dir==0) posX+=v;
    else if(dir==1) posY+=v;
    else if(dir==2) posX-=v;
    else posY-=v;

    setPosition(this->posX,this->posY);
}


void Pacman::setPosition(float x, float y)
{
    this->posX = x;
    this->posY = y;

    int dir = getDirecao();
    float xolho = x;
    float yolho = y;

    this->olho->setPosition(sf::Vector2f(xolho,yolho));
    if      (dir==0) this->olho->move(sf::Vector2f(30.0,5.0));
    else if (dir==1) this->olho->move(sf::Vector2f(5.0,30.0));
    else if (dir==2) this->olho->move(sf::Vector2f(5.0,5.0));
    else             this->olho->move(sf::Vector2f(5.0,5.0));

    this->corpo->setPosition(x,y);
}


void Pacman::memorizaPosicao()
{
    this->ant_posX = this->posX;
    this->ant_posY = this->posY;
}
void Pacman::restauraPosicaoValida()
{
    std::cout << this->posX << "," << this->posY << " - " << this->ant_posX << "," << this->ant_posY << '\n';
    setPosition(this->ant_posX, this->ant_posY);
}

const sf::RectangleShape& Pacman::getShape()
{
    return *(this->corpo);
}


