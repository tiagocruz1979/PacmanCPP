#pragma once
#include <SFML/Graphics.hpp>

class Pacman
{
    public:
        Pacman();
        virtual ~Pacman();

        void setDirecao(int d);
        int getDirecao();
        void draw(sf::RenderWindow *w);
        void mov(float v);
        void setPosition(float x,float y);

        void restauraPosicaoValida();
        void memorizaPosicao();

        const sf::RectangleShape& getShape();

    protected:

    private:
        sf::RectangleShape *corpo;
        sf::RectangleShape *olho;
        int direcao;
        float posX = 0;
        float posY = 0;
        float ant_posX = 0;
        float ant_posY = 0;
};
