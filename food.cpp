#include "food.h"

Food::Food(float x, float y)
{
    this->corpo.setPosition(sf::Vector2f(x,y));
    this->corpo.setFillColor(sf::Color::Magenta);
    this->corpo.setSize(sf::Vector2f(10.0,10.0));
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
