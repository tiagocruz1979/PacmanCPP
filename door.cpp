#include "door.hpp"

Door::Door(int segredo, float posX, float posY,float altura, float largura)
{
        this->segredo = segredo;
        this->posicao.x=posX;
        this->posicao.y=posY;
        this->corpo.setPosition(this->posicao);
        this->corpo.setSize(sf::Vector2f(largura,altura));
        setCor(sf::Color::Yellow);
}

Door::~Door()
{
    //dtor
}

void Door::draw(sf::RenderWindow *w)
{
    w->draw(this->corpo);
}
const sf::RectangleShape& Door::getShape()
{
    return this->corpo;
}

int Door::getSegredo()
{
    return this->segredo;
}

void Door::setCor(sf::Color cor)
{
    this->corpo.setFillColor(cor);
}

void Door::som()
{
    if(!buffer.loadFromFile("recursos/som/porta.wav"))
    {
        //std::cout << "Erro ao abrir arquivo de audio";
    }
    sound.setBuffer(buffer);
    sound.play();
}

