#include "wall.hpp"

Wall::Wall(float x, float y)
{
    this->brick.setPosition(sf::Vector2f(x,y));
    this->brick.setFillColor(sf::Color::Cyan);
    this->brick.setSize(sf::Vector2f(10.f,10.f));
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
