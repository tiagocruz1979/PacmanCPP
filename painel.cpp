#include "painel.hpp"

Painel::~Painel()
{
    //dtor
}
Painel::Painel(std::string caminho)
{
    if(!this->font.loadFromFile(caminho))
    {
        //std::cout << "Erro ao carregar fonte";
    }

    this->rsBorda.setFillColor(sf::Color(0,0,0,0));
    this->rsBorda.setOutlineColor(sf::Color::White);
    this->rsBorda.setOutlineThickness(2.f);
    this->rsBorda.setSize(sf::Vector2f(180,100));

    this->txtName.setCharacterSize(16);
    this->txtName.setFont(this->font);
    this->txtName.setColor(sf::Color::White);

    this->txtRecompensa.setCharacterSize(16);
    this->txtRecompensa.setFont(this->font);
    this->txtRecompensa.setColor(sf::Color::White);

    this->txtobj1.setCharacterSize(16);
    this->txtobj1.setFont(this->font);
    this->txtobj1.setColor(sf::Color::White);


}

void Painel::setNome(std::string nome)
{
    this->txtName.setString(nome);
    this->name = nome;
}

void Painel::setfont(std::string caminho)
{
    this->font.loadFromFile(caminho);
}

void Painel::setPosition(float x, float y)
{
    this->position = sf::Vector2f(x,y);
    this->rsBorda.setPosition(this->position);
    this->txtName.setPosition(this->position);
    this->txtRecompensa.setPosition(this->position);
    this->txtobj1.setPosition(this->position);

    this->txtName.move(sf::Vector2f(5.f,0.f));
    this->txtRecompensa.move(sf::Vector2f(5.f, 20.f));
    this->txtobj1.move(sf::Vector2f(5.f,40.f));


}


void Painel::draw(sf::RenderWindow* w)
{
    atualizar();

    w->draw(this->txtName);
    w->draw(this->rsBorda);
    w->draw(this->txtRecompensa);
    w->draw(this->txtobj1);
}


void Painel::atualizar()
{
    int recompensas = this->pacman->getQuantidadeComida();
    std::string temChave = (this->pacman->getChave()>0?"Sim":"Nao");
    this->txtRecompensa.setString("Recompensas: " + std::to_string(recompensas));
    this->txtobj1.setString("Chave: " + temChave );
}

void Painel::setPacman(Pacman *p)
{
    this->pacman = p;
}
