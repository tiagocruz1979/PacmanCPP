#include "pacman.h"
#include <iostream>

Pacman::Pacman()
{
   std::cout << "Construtor invocado\n";
   this->corpo = new sf::RectangleShape(sf::Vector2f(40.0,40.0));
   this->olho = new sf::RectangleShape(sf::Vector2f(5.0,5.0));
   this->corpo->setFillColor(sf::Color::Yellow);
   this->olho->setFillColor(sf::Color::Black);
   this->direcao = 'D';
   this->key = nullptr;


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
    delete this->key;
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

   direcao = 'D';
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


void Pacman::setDirecao(char d)
{
    this->direcao = d;
}

char Pacman::getDirecao()
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

    if(dir=='D') posX+=v;
    else if(dir=='B') posY+=v;
    else if(dir=='E') posX-=v;
    else if(dir=='C') posY-=v;

    setPosition(this->posX,this->posY);
}


void Pacman::setPosition(float x, float y)
{
    this->posX = x;
    this->posY = y;

    char dir = getDirecao();
    float xolho = x;
    float yolho = y;

    this->olho->setPosition(sf::Vector2f(xolho,yolho));
    if      (dir=='D') this->olho->move(sf::Vector2f(30.0,5.0));
    else if (dir=='B') this->olho->move(sf::Vector2f(5.0,30.0));
    else if (dir=='E') this->olho->move(sf::Vector2f(5.0,5.0));
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

    if(!bufferM.loadFromFile("recursos/som/morte.wav"))//E:\ProjetoCPP\PacmanCPP\recursos\som\sfx-horror7.wav
    {
        std::cout << "Erro ao abrir arquivo de audio";
    }
    soundM.setBuffer(bufferM);
    soundM.play();

    setColor(sf::Color(50,50,50,200));
    this->vivo = false;
}




bool Pacman::pegarChave(Key *key)
{
    if(this->key==nullptr)
    {
        this->key = key;
        return true;
    }
    return false;
}

Key* Pacman::soltarChave()
{
    if(this->key==nullptr) return nullptr;

    sf::Vector2f pos;
    if(this->direcao=='D' || this->direcao=='C')
    {
        pos = sf::Vector2f(this->corpo->getPosition().x+40.f, this->corpo->getPosition().y);
    }
    else
    {
        pos = sf::Vector2f(this->corpo->getPosition().x-10.f, this->corpo->getPosition().y);
    }
    this->key->setPosition(pos);

    return this->key;
}

Key* Pacman::getChave()
{
    return this->key;
}


bool Pacman::comandos(float tempo)
{
        if(sf::Keyboard::isKeyPressed(this->cAcima)) // seta para cima
        {
            setDirecao('C');
            mov(tempo);
        }

        if(sf::Keyboard::isKeyPressed(this->cAbaixo)) // seta para Baixo
        {
            setDirecao('B');
            mov(tempo);
        }
        if(sf::Keyboard::isKeyPressed(this->cEsquerda)) // seta para Esquerda
        {
            setDirecao('E');
            mov(tempo);
        }

        if(sf::Keyboard::isKeyPressed(this->cDireita)) // seta para Direita
        {
            setDirecao('D');
            mov(tempo);
        }
}

void Pacman::setControles(sf::Keyboard::Key acima , sf::Keyboard::Key abaixo , sf::Keyboard::Key direita , sf::Keyboard::Key esquerda , sf::Keyboard::Key solta)
{
    this->cAbaixo = abaixo;
    this->cAcima = acima;
    this->cDireita = direita;
    this->cEsquerda = esquerda;
    this->cSolta = solta;
}


void Pacman::setChave(Key* key)
{
    this->key = key;
}


sf::Keyboard::Key Pacman::getTeclaComando(char comando)
{
    if(comando=='S')
    {
        return this->cSolta;
    }
}

int Pacman::getQuantidadeComida()
{
    return this->comida;
}

sf::Vector2f Pacman::getPosition()
{
    return this->corpo->getPosition();
}
