#pragma once
#include <SFML/Graphics.hpp>
#include <pacman.h>

class Painel
{
    public:
        Painel(std::string caminho);
        virtual ~Painel();

        void setNome(std::string nome);
        void setfont(std::string caminho);
        void setPosition(float x, float y);
        void draw(sf::RenderWindow *w);
        void atualizar();
        void setPacman(Pacman *p);

    protected:

    private:
        std::string name;
        sf::Text txtName;
        sf::Font font;
        sf::Vector2f position;
        sf::RectangleShape rsBorda;
        sf::Text txtRecompensa;
        sf::Text txtobj1;
        Pacman *pacman;


};

