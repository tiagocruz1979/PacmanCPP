#pragma once
#include <SFML/Graphics.hpp>

class Food
{
    public:
        Food(float x,float y);
        virtual ~Food();

        void draw(sf::RenderWindow *w);
        const sf::RectangleShape& getShape();

    protected:

    private:
        sf::RectangleShape corpo;
};


