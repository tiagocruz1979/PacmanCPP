#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Caixa
{
    public:
        Caixa();
        virtual ~Caixa();

        void setPosition(float x, float y);
        sf::Vector2f getPosition();

        void draw(sf::RenderWindow *w);

        bool colisao(const sf::RectangleShape &obj);
        bool colisao(float x, float y, float largura, float altura);

        void memorizarPosicao();
        void restauraPosicao();

        void mov(char direcao, float tempo);

    protected:

    private:
        sf::RectangleShape corpo;
        sf::Vector2f memoPos;
};
