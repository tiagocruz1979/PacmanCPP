#pragma once
#include <SFML/Graphics.hpp>

class Key
{
    public:
        Key(int segredo, float posX, float posY, float altura, float largura);
        virtual ~Key();
        Key(const Key& other);
        Key& operator=(const Key& other);

        void setPosition(sf::Vector2f);
        void draw(sf::RenderWindow *w);
        const sf::RectangleShape& getShape();
        void setColor(sf::Color cor);
        int getSegredo();

    protected:

    private:
        sf::RectangleShape corpo;
        sf::Vector2f posicao;
        sf::Vector2f tamanho;
        int segredo;
};
