#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Pacman
{
    public:
        Pacman();
        virtual ~Pacman();

        //Construtor de C�pias
        Pacman(const Pacman& other);
        Pacman& operator=(const Pacman& other);

        void setDirecao(int d);
        int getDirecao();
        void draw(sf::RenderWindow *w);
        void mov(float v);
        void setPosition(float x,float y);
        void setColor(sf::Color);

        void restauraPosicaoValida();
        void memorizaPosicao();

        const sf::RectangleShape& getShape();

        void comer();
        void morre();

    protected:

    private:
        sf::SoundBuffer bufferM;
        sf::Sound soundM;

        sf::SoundBuffer buffer;
        sf::Sound sound;
        sf::RectangleShape *corpo;
        sf::RectangleShape *olho;
        int direcao;
        float posX = 0;
        float posY = 0;
        float ant_posX = 0;
        float ant_posY = 0;
        int comida = 0;
        bool vivo = true;
};
