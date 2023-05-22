#pragma once
#include <SFML/Graphics.hpp>

class Wall
{
    public:
        Wall(float x , float y);
        virtual ~Wall();

        void draw(sf::RenderWindow *w);
        const sf::RectangleShape& getShape();

    protected:

    private:
        sf::RectangleShape brick;
};
