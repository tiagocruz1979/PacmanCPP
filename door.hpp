#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Door
{
    public:
        Door(int segredo, float posX, float posY,float altura, float largura);
        virtual ~Door();

        void draw(sf::RenderWindow *w);
        const sf::RectangleShape& getShape();
        void setCor(sf::Color cor);

        int getSegredo();
        void som();

    protected:

    private:
        sf::RectangleShape corpo;
        sf::Vector2f posicao;
        float largura;
        float altura;
        int segredo;
        sf::SoundBuffer buffer;
        sf::Sound sound;
};

