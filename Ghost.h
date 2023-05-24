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
        void setColor(sf::Color &cor);

        void draw(sf::RenderWindow *w);


    protected:

    private:
        sf::RectangleShape *corpo;
        sf::RectangleShape *olho[2];
        sf::RectangleShape *base[4];
};


