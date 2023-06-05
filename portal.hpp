#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Portal
{
    public:
        Portal();
        virtual ~Portal();

        void draw(sf::RenderWindow *w);
        void setColor(sf::Color cor);
        void setPosTransportation(sf::Vector2f destino);
        void setPosition(float x, float y);
        sf::Vector2f getDestino();
        const sf::RectangleShape& getShape();
        void som();
        sf::Vector2f getPosition();



    protected:

    private:
        sf::RectangleShape *corpo;
        float x,y;
        sf::SoundBuffer buffer;
        sf::Sound sound;
};


