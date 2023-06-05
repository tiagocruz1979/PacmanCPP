#include "caixa.hpp"

Caixa::Caixa()
{
    this->corpo.setSize(sf::Vector2f(40.f,40.f));
    this->corpo.setFillColor(sf::Color::Green);
}

Caixa::~Caixa()
{
    //dtor
}
void Caixa::setPosition(float x, float y)
{
    this->corpo.setPosition(sf::Vector2f(x,y));
}

sf::Vector2f Caixa::getPosition()
{
    return this->corpo.getPosition();
}

void Caixa::draw(sf::RenderWindow* w)
{
    w->draw(this->corpo);
}






void Caixa::memorizarPosicao()
{
  //  std::cout << "Memorizando a posicao " << this->corpo.getPosition().x << ',' << this->corpo.getPosition().y << '\n';
    this->memoPos = this->corpo.getPosition();
}

void Caixa::restauraPosicao()
{
    //std::cout << "Posicao Atual " << this->corpo.getPosition().x << ',' << this->corpo.getPosition().y << '\n';
    //std::cout << "Restaurando a posicao " << memoPos.x << ',' << memoPos.y << '\n';
    setPosition(memoPos.x,memoPos.y);
}

void Caixa::mov(char direcao, float tempo)
{
    float x = getPosition().x;
    float y = getPosition().y;

    if(direcao=='D') x+=tempo;
    else if(direcao=='E') x-=tempo;
    else if(direcao=='C') y-=tempo;
    else if(direcao=='B') y+=tempo;

    setPosition(x,y);
}
