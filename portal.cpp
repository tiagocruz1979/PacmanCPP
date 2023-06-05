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

void Portal::setPosTransportation(sf::Vector2f destino)
{
    this->x = destino.x;
    this->y = destino.y;
}

sf::Vector2f Portal::getDestino()
{
    return sf::Vector2f(this->x, this->y);
}
void Portal::setPosition(float x, float y)
{
    this->corpo->setPosition(sf::Vector2f(y,x));
}
sf::Vector2f Portal::getPosition()
{
    return sf::Vector2f(this->corpo->getPosition().x, this->corpo->getPosition().y);
}

const sf::RectangleShape& Portal::getShape()
{
    return *this->corpo;
}

void Portal::som()
{
    if(!buffer.loadFromFile("recursos/som/transporte.wav"))
    {
        //std::cout << "Erro ao abrir arquivo de audio";
    }
    sound.setBuffer(buffer);
    sound.play();
}
