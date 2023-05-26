#include "pacman.h"
#include <iostream>

Pacman::Pacman()
{
   std::cout << "Construtor invocado\n";
   this->corpo = new sf::RectangleShape(sf::Vector2f(40.0,40.0));
   this->olho = new sf::RectangleShape(sf::Vector2f(5.0,5.0));
   this->corpo->setFillColor(sf::Color::Yellow);
   this->olho->setFillColor(sf::Color::Black);
   direcao = 0; // 0 = Direita , 1 = baixo , 2 = esquerda , 3 = cima

    if (!this->buffer.loadFromFile("recursos/som/sfx-pop.wav")) {
        // Tratar o erro caso o arquivo não seja carregado corretamente
        std::cout << "arquivo de audio nao carregado\n";
    }
    this->sound.setBuffer(buffer);

}

Pacman::~Pacman() // destrutor
{
    delete this->olho;
    delete this->corpo;
}

Pacman::Pacman(const Pacman& other) // construtor de cópias
{
   std::cout << "Construtor de copias invocado\n";

    this->direcao = other.direcao;
    this->posX = other.posX;
    this->posY = other.posY;
    this->ant_posX = other.ant_posX;
    this->ant_posY = other.ant_posY;

   this->corpo = new sf::RectangleShape();
   this->corpo->setFillColor(other.corpo->getFillColor());
   this->corpo->setSize(other.corpo->getSize());
   this->olho = new sf::RectangleShape();
   this->olho->setFillColor(other.olho->getFillColor());
   this->olho->setSize(other.olho->getSize());
   setPosition(this->posX,this->posY);

   direcao = 0; // 0 = Direita , 1 = baixo , 2 = esquerda , 3 = cima
}

Pacman& Pacman::operator=(const Pacman& other) {
   std::cout << "operator= invocado\n";

    if (this == &other) {  // Verifica se é a mesma instância
        return *this;
    }

    // Copia os membros da instância original para a nova instância
    this->direcao = other.direcao;
    this->posX = other.posX;
    this->posY = other.posY;
    this->ant_posX = other.ant_posX;
    this->ant_posY = other.ant_posY;

    this->corpo->setFillColor(other.corpo->getFillColor());
    this->corpo->setSize(other.corpo->getSize());
    this->olho->setFillColor(other.olho->getFillColor());
    this->olho->setSize(other.olho->getSize());
    setPosition(this->posX,this->posY);

    return *this;
}


void Pacman::setDirecao(int d)
{
    this->direcao = d;
}

int Pacman::getDirecao()
{
    return this->direcao;
}

void Pacman::draw(sf::RenderWindow* w)
{
    w->draw(*corpo);
    w->draw(*olho);
}


void Pacman::mov(float v)
{

    if(vivo==false) return;

    int dir = getDirecao();

    if(dir==0) posX+=v;
    else if(dir==1) posY+=v;
    else if(dir==2) posX-=v;
    else posY-=v;

    setPosition(this->posX,this->posY);
}


void Pacman::setPosition(float x, float y)
{
    this->posX = x;
    this->posY = y;

    int dir = getDirecao();
    float xolho = x;
    float yolho = y;

    this->olho->setPosition(sf::Vector2f(xolho,yolho));
    if      (dir==0) this->olho->move(sf::Vector2f(30.0,5.0));
    else if (dir==1) this->olho->move(sf::Vector2f(5.0,30.0));
    else if (dir==2) this->olho->move(sf::Vector2f(5.0,5.0));
    else             this->olho->move(sf::Vector2f(5.0,5.0));

    this->corpo->setPosition(x,y);
}


void Pacman::memorizaPosicao()
{
    this->ant_posX = this->posX;
    this->ant_posY = this->posY;
}

void Pacman::restauraPosicaoValida()
{
    //std::cout << this->posX << "," << this->posY << " - " << this->ant_posX << "," << this->ant_posY << '\n';
    setPosition(this->ant_posX, this->ant_posY);
}

const sf::RectangleShape& Pacman::getShape()
{
    return *(this->corpo);
}

void Pacman::setColor(sf::Color c)
{
    this->corpo->setFillColor(c);
}

void Pacman::comer()
{
    this->comida++;
    this->sound.play();
}

void Pacman::morre()
{
    if(!this->vivo) return;

    if(!bufferM.loadFromFile("recursos/som/sfx-horror7.wav"))//E:\ProjetoCPP\PacmanCPP\recursos\som\sfx-horror7.wav
    {
        std::cout << "Erro ao abrir arquivo de audio";
    }
    soundM.setBuffer(bufferM);
    soundM.play();

    setColor(sf::Color(50,50,50,200));
    this->vivo = false;
}

