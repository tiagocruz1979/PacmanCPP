#include "Ghost.h"

Ghost::Ghost()
{
<<<<<<< HEAD
    this->cabeca = new sf::RectangleShape(sf::Vector2f(30.f,5.f));
    this->corpo = new sf::RectangleShape(sf::Vector2f(40.f,30.f));
    this->olho[0] = new sf::RectangleShape(sf::Vector2f(10.f,10.f));
    this->olho[1] = new sf::RectangleShape(sf::Vector2f(10.f,10.f));
=======
    this->corpo = new sf::RectangleShape(sf::Vector2f(40.f,40.f));
    this->olho[0] = new sf::RectangleShape(sf::Vector2f(5.f,5.f));
    this->olho[1] = new sf::RectangleShape(sf::Vector2f(5.f,5.f));
>>>>>>> 8d2823b0164ba5196cc18c056cfa0bab944862a7
    for(int i = 0 ; i < 4 ; i++)
    {
        this->base[i] = new sf::RectangleShape(sf::Vector2f(5.f,5.f));
    }

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
<<<<<<< HEAD
    this->cabeca->setPosition(sf::Vector2f(x+5.f,y));
    this->corpo->setPosition(sf::Vector2f(x,y+5.f));
    this->olho[0]->setPosition(sf::Vector2f(x,y));
    this->olho[1]->setPosition(sf::Vector2f(x,y));
    this->olho[0]->move(sf::Vector2f(5.f,8.f));
    this->olho[1]->move(sf::Vector2f(25.f,8.f));
=======
    this->corpo->setPosition(sf::Vector2f(x,y));
    this->olho[0]->setPosition(sf::Vector2f(x,y));
    this->olho[1]->setPosition(sf::Vector2f(x,y));
    this->olho[0]->move(sf::Vector2f(5.f,5.f));
    this->olho[1]->move(sf::Vector2f(30.f,5.f));
>>>>>>> 8d2823b0164ba5196cc18c056cfa0bab944862a7

    float h = this->corpo->getSize().y + 5.f;
    for(int i = 0 ; i < 4 ; i++)
    {
<<<<<<< HEAD
        this->base[i]->setPosition(sf::Vector2f(x+(i*10),y));
=======
        this->base[i]->setPosition(sf::Vector2f(x*10,y));
>>>>>>> 8d2823b0164ba5196cc18c056cfa0bab944862a7
        this->base[i]->move(sf::Vector2f(0,h));
    }

}

<<<<<<< HEAD
void Ghost::setColor(sf::Color cor)
{
    this->cabeca->setFillColor(cor);
    this->corpo->setFillColor(cor);
    this->olho[0]->setFillColor(sf::Color::Black);
    this->olho[1]->setFillColor(sf::Color::Black);
=======
void Ghost::setColor(sf::Color& cor)
{
    this->corpo->setFillColor(cor);
>>>>>>> 8d2823b0164ba5196cc18c056cfa0bab944862a7
    for(int i = 0 ; i < 4 ; i++)
    {
        this->base[i]->setFillColor(cor);
    }
}


void Ghost::draw(sf::RenderWindow *w)
{
<<<<<<< HEAD
    w->draw(*this->cabeca);
=======
>>>>>>> 8d2823b0164ba5196cc18c056cfa0bab944862a7
    w->draw(*this->corpo);
    w->draw(*this->olho[0]);
    w->draw(*this->olho[1]);
    for(int i = 0 ; i < 4 ; i++)
    {
        w->draw(*this->base[i]);
    }

}

