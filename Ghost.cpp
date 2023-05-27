#include "Ghost.h"
#include <ctime>
#include <cmath>
#include <iostream>

Ghost::Ghost()
{
    this->direcao = 'D';
    this->cabeca = new sf::RectangleShape(sf::Vector2f(30.f,5.f));
    this->corpo = new sf::RectangleShape(sf::Vector2f(40.f,30.f));
    this->olho[0] = new sf::RectangleShape(sf::Vector2f(10.f,10.f));
    this->olho[1] = new sf::RectangleShape(sf::Vector2f(10.f,10.f));

    for(int i = 0 ; i < 4 ; i++)
    {
        this->base[i] = new sf::RectangleShape(sf::Vector2f(5.f,5.f));
    }
    setColor(gerarCor());

}

Ghost::~Ghost()
{
    delete this->corpo;
    delete this->olho[0];
    delete this->olho[1];
    for(int i = 0 ; i < 4 ; i++)
        delete this->base[i];
}

Ghost::Ghost(const Ghost& other)
{
    //copy ctor
}

Ghost& Ghost::operator=(const Ghost& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
void Ghost::setPosition(float x, float y)
{
    this->cabeca->setPosition(sf::Vector2f(x+5.f,y));
    this->corpo->setPosition(sf::Vector2f(x,y+5.f));
    this->olho[0]->setPosition(sf::Vector2f(x,y));
    this->olho[1]->setPosition(sf::Vector2f(x,y));
    this->olho[0]->move(sf::Vector2f(5.f,8.f));
    this->olho[1]->move(sf::Vector2f(25.f,8.f));


    float h = this->corpo->getSize().y + 5.f;
    for(int i = 0 ; i < 4 ; i++)
    {
        this->base[i]->setPosition(sf::Vector2f(x+(i*10),y));

        this->base[i]->move(sf::Vector2f(0,h));
    }
}

sf::Vector2f Ghost::getPosition()
{
    return sf::Vector2f(this->corpo->getPosition().x, this->corpo->getPosition().y-5.f);
}


void Ghost::setColor(sf::Color cor)
{
    this->cabeca->setFillColor(cor);
    this->corpo->setFillColor(cor);
    this->olho[0]->setFillColor(sf::Color(0,0,255,100));
    this->olho[1]->setFillColor(sf::Color(0,0,255,100));
    for(int i = 0 ; i < 4;i++)
    {
        this->base[i]->setFillColor(cor);
    }
}


void Ghost::draw(sf::RenderWindow *w)
{
    w->draw(*this->cabeca);
    w->draw(*this->corpo);
    w->draw(*this->olho[0]);
    w->draw(*this->olho[1]);
    for(int i = 0 ; i < 4 ; i++)
    {
        w->draw(*this->base[i]);
    }
}

sf::Color Ghost::gerarCor()
{
    static int idCor = 0 ;
    if(idCor==0)
    {
        idCor++;
        return sf::Color::Green;
    }
    else if(idCor==1)
    {
        idCor++;
        return sf::Color::Cyan;
    }
    else if(idCor==2)
    {
        idCor++;
        return sf::Color::Red;
    }
    else
    {
        idCor=0;
        return sf::Color::White;
    }
}
void Ghost::girarHor()
{
    char d = this->direcao;
    char g;
    if(d=='D') g='B';
    else if(d=='B') g='E';
    else if(d=='E') g='C';
    else g='D';
    this->direcao = g;
}

void Ghost::girarAnti()
{
    char d = this->direcao;
    char g;
    if(d=='D') g='C';
    else if(d=='C') g='E';
    else if(d=='E') g='B';
    else g='D';
    this->direcao = g;
}

void Ghost::girarRandom()
{
    int r = rand()%2;
    if(r==0) girarHor();
    else girarAnti();
}

void Ghost::mov(float v)
{
    char d = this->direcao;
    sf::Vector2f pos = getPosition();
    float x = pos.x;
    float y = pos.y;

    if(d=='B') y+=v;
    else if(d=='E') x-=v;
    else if(d=='C') y-=v;
    else x+=v;

    setPosition(x,y);
}
void Ghost::memorizarPosicao()
{
    sf::Vector2f pos = getPosition();
    this->memoPosX = pos.x;
    this->memoPosY = pos.y;
}

void Ghost::restaurarPosicao()
{
    setPosition(memoPosX,memoPosY);
}

bool Ghost::colision(const sf::RectangleShape &s)
{
    if(s.getGlobalBounds().intersects(this->corpo->getGlobalBounds()))
    {
        return true;
    }
    else if(s.getGlobalBounds().intersects(this->cabeca->getGlobalBounds()))
    {
        return true;
    }
    else
    {
        for(int i = 0 ; i < 4 ; i++)
        {
            if(s.getGlobalBounds().intersects(this->base[i]->getGlobalBounds()))
            {
                return true;
            }
        }
    }
    return false;
}



