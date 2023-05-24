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
<<<<<<< HEAD
        void setColor(sf::Color cor);
=======
        void setColor(sf::Color &cor);
>>>>>>> 8d2823b0164ba5196cc18c056cfa0bab944862a7

        void draw(sf::RenderWindow *w);


    protected:

    private:
<<<<<<< HEAD
        sf::RectangleShape *cabeca;
=======
>>>>>>> 8d2823b0164ba5196cc18c056cfa0bab944862a7
        sf::RectangleShape *corpo;
        sf::RectangleShape *olho[2];
        sf::RectangleShape *base[4];
};


