#include "game.h"
#include <iostream>

void Game::finalizar()
{
    delete this->window;
}

void Game::inicializar(sf::RenderWindow *w)
{
    this->window = w;

    //if(!this->imgPacman.loadFromFile("recursos/imagem/pacman.png"))
   // {
    //std::cout << "Erro ao abrir imagem\n";
    //}
    //if(!this->imgFundo.loadFromFile("recursos/imagem/fundo1.png"))
   // {
   // std::cout << "Erro ao abrir imagem\n";
   // }


    //sf::IntRect rectTexture(100,130,100,100);
    //this->sptPacman.setTexture(this->imgPacman);
    //this->sptPacman.setPosition(sf::Vector2f(100,100));
    //this->sptPacman.setTextureRect(rectTexture);
    //this->sptPacman.setScale(sf::Vector2f(0.5,0.5));


    Pacman *p1 = new Pacman();
    p1->setPosition(550.f,430.f);
    p1->memorizaPosicao();
    p1->setColor(sf::Color::Blue);
    p1->setControles(sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Right,sf::Keyboard::Left,sf::Keyboard::P);
    this->pacman.push_back(p1);

    Painel *pa1 = new Painel("recursos/font/consola.ttf");
    pa1->setNome("Player 1");
    pa1->setPosition(820,10);
    pa1->setPacman(p1);
    this->paineis.push_back(pa1);


    Pacman *p2 = new Pacman();
    p2->setPosition(10.f,60.f);
    p2->setColor(sf::Color::Red);
    p2->memorizaPosicao();
    p2->setControles(sf::Keyboard::W,sf::Keyboard::S,sf::Keyboard::D,sf::Keyboard::A,sf::Keyboard::Z);
    this->pacman.push_back(p2);

    Painel *pa2 = new Painel("recursos/font/consola.ttf");
    pa2->setNome("Player 2");
    pa2->setPosition(820,150);
    pa2->setPacman(p2);
    this->paineis.push_back(pa2);

    int idxCenario = 0;
    int idxPortal = 0;
    std::vector<std::string> &cen = getCenario(idxCenario);

    int linhas = cen.size();
    for(int i = 0 ; i < linhas; i++)
    {
        int colunas = cen.at(i).size();
        for(int j = 0 ; j < colunas ; j++)
        {
            char c = cen.at(i).at(j);
            if(c=='f')
            {
                Food *f = new Food(8.f,8.f);
                f->setColor(sf::Color::Blue);
                f->setPosition(j*10.f,i*10.f);
                this->foods.push_back(f);
            }
            else if (c=='p')
            {
                Wall *b = new Wall(10.f,10.f);
                b->setColor(sf::Color::Cyan);
                b->setPosition(j*b->getSize().x, i*b->getSize().y);
                this->bricks.push_back(b);
            }
            else if(c=='t') // portal de transporte
            {
                //std::cout << "Criando portal \n";
                Portal *p1 = new Portal();
                p1->setColor(sf::Color(100,50,50,255));
                p1->setPosition(i*10.f,j*10.f);
                p1->setPosTransportation(getDestinoPortal(idxCenario,idxPortal));

                sf::RectangleShape pd;
                pd.setPosition(p1->getDestino());
                pd.setFillColor(sf::Color(150,150,50,200));
                pd.setSize(sf::Vector2f(40.f,40.f));

                idxPortal++;

                this->portalDestino.push_back(pd);
                this->portais.push_back(p1);
            }
            else if(c=='g') // criando os fantasmas
            {
                Ghost *g = new Ghost();
                g->setPosition(j*10.f,i*10.f);
                this->ghosts.push_back(g);
            }
            else if(c=='d') // porta vertical
            {
                Door *d = new Door(1001,j*10.f,i*10.f,40.f,10.f);
                this->doors.push_back(d);
            }
            else if(c=='D') // porta horizontal
            {
                Door *d = new Door(1001,j*10.f,i*10.f,10.f,40.f);
                this->doors.push_back(d);
            }
            else if(c=='k') // chave
            {
                Key *k = new Key(1001,j*10.f,i*10.f,20.f,10.f);
                this->keys.push_back(k);
            }
            else if(c=='b')
            {
                Caixa *b = new Caixa();
                b->setPosition(j*10.f,i*10.f);
                b->memorizarPosicao();
                this->caixas.push_back(b);
            }
        }
    }

}

void Game::processarEntrada(sf::Event *event, float tempo)
{

    // movimento do Pacman
    for(Pacman *p : this->pacman)
    {
        p->memorizaPosicao();
        p->comandos(0.5);

        if(sf::Keyboard::isKeyPressed(p->getTeclaComando('S'))) // soltar a chave
        {
            Key *k = p->soltarChave();
            if(k!=nullptr)
            {
                this->keys.push_back(k);
                p->setChave(nullptr);
                break;
            }
        }
    }

    //movimento dos Fantasmas
    for(Ghost *g : this->ghosts)
    {
        g->memorizarPosicao();
        g->mov(0.25);
    }


    //colisoes

    //colisão com parede
    int vSize = 0;


    //colisao da caixa com o pacman - mover caixa
    for(Caixa *c: this->caixas)
    {
        c->memorizarPosicao();
        for(Pacman *p : this->pacman)
        {
            bool colisao = verificarInterseccao(c->getPosition().x,c->getPosition().y,40.f,40.f,p->getPosition().x, p->getPosition().y,40.f,40.f);
            if(colisao)
            {
                char dir = p->getDirecao();
                c->mov(dir,0.50);
            }
        }
    }
    //colisao da caixa com parede - restaurar posicao
    for(Wall *b: this->bricks)
    {
        for(Caixa *c: this->caixas)
        {
            bool colisao = verificarInterseccao(c->getPosition().x,c->getPosition().y,40.f,40.f,b->getPosition().x, b->getPosition().y,10.f,10.f);
            if(colisao)
            {
                c->restauraPosicao();

                //verificar se afeta posicao do pacman
                for(Pacman *p: this->pacman)
                {
                    bool colisao = verificarInterseccao(c->getPosition().x,c->getPosition().y,40.f,40.f,p->getPosition().x, p->getPosition().y,40.f,40.f);
                    if(colisao)
                    {
                        p->restauraPosicaoValida();
                    }
                }
            }
        }
    }


    //colisao do pacman com a Parede
    for(Pacman *p : this->pacman)
    {
        for(Wall *b : this->bricks)
        {
            bool colisao = verificarInterseccao(p->getPosition().x,p->getPosition().y,40.f,40.f,b->getPosition().x, b->getPosition().y,10.f,10.f);
            if(colisao)
            {
                p->restauraPosicaoValida();
            }
        }
    }
    //colisao pacman com fantastama
    for(Pacman *p :  this->pacman)
    {
        for(Ghost *g : this->ghosts)
        {
            bool colisao = verificarInterseccao(p->getPosition().x,p->getPosition().y,40.f,40.f,g->getPosition().x, g->getPosition().y,40.f,40.f);
            if(colisao)
            {
                p->morre();
            }
        }
    }

    // colisão pacman com portal
    for(Pacman *p :  this->pacman)
    {
        for(Portal *d : this->portais)
        {
            bool colisao = verificarInterseccao(p->getPosition().x,p->getPosition().y,40.f,40.f,d->getPosition().x, d->getPosition().y,40.f,40.f);
            if(colisao)
            {
                p->setPosition(d->getDestino().x,d->getDestino().y);
                d->som();
            }
        }
    }
    // colisão pacman com comida
    vSize = static_cast<int>(this->foods.size());
    int idelete = -1;
    for(int i =0; i < vSize ;i++)
    {
        for(Pacman *p : this->pacman)
        {
            bool colisao = verificarInterseccao(p->getPosition().x,p->getPosition().y,40.f,40.f,foods.at(i)->getPosition().x, foods.at(i)->getPosition().y,5.f,5.f);
            if(colisao)
            {
                idelete = i;
                p->comer();
            }
        }
    }
    if(idelete>=0)
    {
        Food *itemDeletar = this->foods.at(idelete);
        this->foods.erase(this->foods.begin()+idelete);
        delete itemDeletar;
    }

    // colisao do Pacman com a chave
    int key_deletar = -1;
    int i = 0;
    for(Key *k : this->keys)
    {
        for(Pacman *p : this->pacman)
        {
            bool colisao = verificarInterseccao(p->getPosition().x,p->getPosition().y,40.f,40.f,k->getPosition().x,k->getPosition().y,k->getShape().getSize().x, k->getShape().getSize().y);
            if(colisao)
            {
                if(p->pegarChave(k))
                {
                    key_deletar = i;
                }
            }
        }
    i++;
    }
    if(key_deletar>=0) this->keys.erase(this->keys.begin()+key_deletar);

    //colisao do Pacman com a porta
    vSize = static_cast<int>(this->doors.size());
    idelete=-1;
    for(int i = 0 ; i < vSize ;i++)
    {
        for(Pacman *p : this->pacman)
        {
            if(p->getShape().getGlobalBounds().intersects(this->doors.at(i)->getShape().getGlobalBounds()))
            {
                if(p->getChave() != nullptr && p->getChave()->getSegredo()==this->doors.at(i)->getSegredo())
                {
                    this->doors.at(i)->som();
                    idelete = i;
                    p->setChave(nullptr);
                    break;
                 }
                 else
                 {
                    std::cout << "Tipo incorreto da chave\n";
                    p->restauraPosicaoValida();
                 }
             }
        }
    }
    if(idelete>=0) this->doors.erase(this->doors.begin()+idelete);



    //Colisao do Fantasma com a Parede
    for(Wall *b : this->bricks)
    {
        for(Ghost *g : this->ghosts)
        {
            bool colisao = verificarInterseccao(b->getPosition().x,b->getPosition().y, 10.f,10.f,g->getPosition().x,g->getPosition().y,40.f,40.f);
            if(colisao)
            {
                g->restaurarPosicao();
                g->girarRandom();
            }
        }
    }
    // colisão Fantasma com portal
    for(Ghost *g :  this->ghosts)
    {
        for(Portal *d : this->portais)
        {
            bool colisao = verificarInterseccao(g->getPosition().x,g->getPosition().y,40.f,40.f,d->getPosition().x, d->getPosition().y,40.f,40.f);
            if(colisao)
            {
                g->setPosition(d->getDestino().x,d->getDestino().y);
                d->som();
            }
        }
    }
    //colisao do Fantasma com a Caixa
    for(Ghost *g :  this->ghosts)
    {
        for(Caixa *c : this->caixas)
        {
            bool colisao = verificarInterseccao(g->getPosition().x,g->getPosition().y,40.f,40.f,c->getPosition().x, c->getPosition().y,40.f,40.f);
            if(colisao)
            {
                g->girarAnti();
                g->girarAnti();
            }
        }
    }


}


void Game::atualizar(float tempo)
{

}


void Game::renderizar()
{

    int vSize = 0;

    vSize = static_cast<int>(this->foods.size());
    for(int i = 0 ; i < vSize ;i++)
    {
        this->foods.at(i)->draw(this->window);
    }
    vSize = static_cast<int>(this->bricks.size());
    for(int i = 0 ; i < vSize ;i++)
    {
        this->bricks.at(i)->draw(this->window);
    }


    vSize = static_cast<int>(this->portais.size());
    for(int i = 0 ; i < vSize ;i++)
    {
        this->portais.at(i)->draw(this->window);
    }
    vSize = static_cast<int>(this->portalDestino.size());
    for(int i = 0 ; i < vSize ;i++)
    {
        this->window->draw(portalDestino.at(i));
    }


    int nGhosts = this->ghosts.size();
    for(int i = 0 ; i < nGhosts;i++)
    {
        this->ghosts.at(i)->draw(this->window);
    }

    int nDoors = this->doors.size();
    for(int i = 0 ; i < nDoors;i++)
    {
        this->doors.at(i)->draw(this->window);
    }

    int nKeys = this->keys.size();
    for(int i = 0 ; i < nKeys;i++)
    {
        this->keys.at(i)->draw(this->window);
    }

    for(Pacman *p : this->pacman)
    {
        p->draw(this->window);
    }

    for(Painel *p : this->paineis)
    {
        p->draw(this->window);
    }

    for(Caixa *b : this->caixas)
    {
        b->draw(this->window);
    }


}

Game::Game()
{

}

Game::~Game()
{
    int n = this->foods.size();
    for(int i = 0 ; i < n;i++)
    {
        delete this->foods.at(i);
        this->foods.pop_back();
    }

    n = this->ghosts.size();
    for(int i = 0 ; i < n;i++)
    {
        delete this->ghosts.at(i);
        this->ghosts.pop_back();
    }

    n = this->doors.size();
    for(int i = 0 ; i < n ; i++)
    {
        delete this->doors.at(i);
        this->doors.pop_back();
    }

    n = this->pacman.size();
    for(int i = 0 ; i < n ; i++)
    {
        delete this->pacman.at(i);
        this->pacman.pop_back();
    }

}



