#include "food.h"

Food::Food(float largura, float altura)
{
    setPosition(0.0,0.0);
    setColor(sf::Color::Magenta);
    this->setSize(largura,altura);
}

Food::~Food()
{
    //dtor
}


void Food::draw(sf::RenderWindow *w)
{
    w->draw(this->corpo);
}


const sf::RectangleShape& Food::getShape()
{
    return this->corpo;
}


void Food::setColor(sf::Color cor)
{
    this->corpo.setFillColor(cor);
}


const sf::Vector2f Food::getSize()
{
    return this->corpo.getSize();
}


void Food::setPosition(float x, float y)
{
    this->corpo.setPosition(sf::Vector2f(x,y));
}


sf::Vector2f Food::getPosition()
{
    return this->corpo.getPosition();
}

void Food::setSize(float largura, float altura)
{
    this->corpo.setSize(sf::Vector2f(largura,altura));
}
