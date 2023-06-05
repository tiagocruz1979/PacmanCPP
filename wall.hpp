#pragma once
#include <SFML/Graphics.hpp>

class Wall
{
    public:
        Wall(float largura , float altura);
        virtual ~Wall();

        void setColor(sf::Color cor);
        void setPosition(float x, float y);
        void draw(sf::RenderWindow *w);
        const sf::RectangleShape& getShape();
        const sf::Vector2f getPosition();
        const sf::Vector2f getSize();

    protected:

    private:
        sf::RectangleShape brick;
};

