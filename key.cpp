#include "key.hpp"

Key::Key(int segredo, float posX, float posY, float altura, float largura)
{
    this->posicao = sf::Vector2f(posX,posY);
    this->tamanho = sf::Vector2f(largura,altura);
    this->corpo.setPosition(this->posicao);
    this->corpo.setSize(this->tamanho);
    this->segredo = segredo;
}

Key::~Key()
{
    //dtor
}

Key::Key(const Key& other)
{
    //copy ctor
}

Key& Key::operator=(const Key& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
void Key::draw(sf::RenderWindow* w)
{
     w->draw(this->corpo);
}

const sf::RectangleShape& Key::getShape()
{
    return this->corpo;
}

int Key::getSegredo()
{
    return this->segredo;
}
void Key::setPosition(sf::Vector2f pos)
{
    this->corpo.setPosition(pos);
}

void Key::setColor(sf::Color cor)
{
    this->corpo.setFillColor(cor);
}

sf::Vector2f Key::getPosition()
{
    return sf::Vector2f(this->corpo.getPosition().x, this->corpo.getPosition().y);
}


