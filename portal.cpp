#include "portal.hpp"

Portal::Portal()
{
    this->corpo = new sf::RectangleShape();
    this->corpo->setSize(sf::Vector2f(40.f,40.f));
}

Portal::~Portal()
{
    delete this->corpo;
}
void Portal::draw(sf::RenderWindow* w)
{
    w->draw(*this->corpo);
}

void Portal::setColor(sf::Color cor)
{
    this->corpo->setFillColor(cor);
}

void Portal::setPosTransportation(float x, float y)
{
    this->x = x;
    this->y = y;
}

sf::Vector2f Portal::getDestino()
{
    return sf::Vector2f(this->x, this->y);
}
void Portal::setPosition(float x, float y)
{
    this->corpo->setPosition(sf::Vector2f(y,x));
}

const sf::RectangleShape& Portal::getShape()
{
    return *this->corpo;
}
