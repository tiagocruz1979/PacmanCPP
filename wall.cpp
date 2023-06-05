#include "wall.hpp"

Wall::Wall(float x, float y)
{
    this->brick.setFillColor(sf::Color::Cyan);
    this->brick.setSize(sf::Vector2f(x,y));
}


Wall::~Wall()
{

}

void Wall::draw(sf::RenderWindow *w)
{
    w->draw(this->brick);
}

const sf::RectangleShape& Wall::getShape()
{
    return this->brick;
}

const sf::Vector2f Wall::getPosition()
{
    return this->brick.getPosition();
}

const sf::Vector2f Wall::getSize()
{
    return this->brick.getSize();
}

void Wall::setColor(sf::Color cor)
{
    this->brick.setFillColor(cor);
}

void Wall::setPosition(float x, float y)
{
    this->brick.setPosition(sf::Vector2f(x,y));
}
