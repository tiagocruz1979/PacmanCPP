#pragma once
#include <SFML/Graphics.hpp>

class Food
{
    public:
        Food(float largura,float altura);
        virtual ~Food();

        void draw(sf::RenderWindow *w);
        const sf::RectangleShape& getShape();
        void setColor(sf::Color cor);
        const sf::Vector2f getSize();
        void setPosition(float x, float y);
        sf::Vector2f getPosition();
        void setSize(float largura,float altura);

    protected:

    private:
        sf::RectangleShape corpo;
};


