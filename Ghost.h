#pragma once
#include <SFML/Graphics.hpp>

class Ghost
{
    public:
        Ghost();
        virtual ~Ghost();
        Ghost(const Ghost& other);
        Ghost& operator=(const Ghost& other);

        void setPosition(float x, float y);
        sf::Vector2f getPosition();

        void setColor(sf::Color cor);

        void draw(sf::RenderWindow *w);

        sf::Color gerarCor(int i=0);

        void girarHor();
        void girarAnti();
        void girarRandom();
        void mov(float v);

        void memorizarPosicao();
        void restaurarPosicao();

        bool colision(const sf::RectangleShape &s);

    protected:

    private:
        char direcao;
        float memoPosX, memoPosY;
        sf::RectangleShape *cabeca;

        sf::RectangleShape *corpo;
        sf::RectangleShape *olho[2];
        sf::RectangleShape *base[4];
};


