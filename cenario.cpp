#include "cenario.h"

std::vector<std::string>& getCenario(int index) {
    if (index == 1)
    {
        return cenario1;
    }
    else if(index == 2)
    {
        return cenario2;
    }

    return cenario0;
}

sf::Vector2f getDestinoPortal(int idCenario,int idPortal)
{
    if(idCenario==0)
    {
        switch (idPortal)
        {
            case 0:
                return sf::Vector2f(500.f,420.f);
            break;
            case 1:
                return sf::Vector2f(210.f,150.f);
            break;
            default:
                return sf::Vector2f(80.f,10.f);
        }
    }
    else if(idCenario==1)
    {
        switch (idPortal)
        {
            case 0:
                return sf::Vector2f(20.f,20.f);
            break;
            default:
                return sf::Vector2f(200.f,200.f);
        }
    }
    else if(idCenario==2)
    {
        switch (idPortal)
        {
            case 0:
                return sf::Vector2f(20.f,20.f);
            break;
            default:
                return sf::Vector2f(200.f,200.f);
        }
    }

    return sf::Vector2f(10.f,10.f);
}

std::vector<std::string> cenario0 = {
{"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp"},
{"p     pp                        ppp                                            p"},
{"p     pp                        ppp                                            p"},
{"p     pp  f  f  f  f     fff    ppp  f  f    f    f    f   f  f   f  f  f  f   p"},
{"p     pp                        ppp                                            p"},
{"p     pp  f                     ppp                               f   pppppppppp"},
{"p     pp     ppppppppp   fff    ppp  f  ppppppppppppppppppppppp       pppppppppp"},
{"p  f  pp  f  ppppppppp          ppp                               f   pppppppppp"},
{"p     pp                        ppp                                   pppp     p"},
{"p     pp  f    f    f    fff         f    f   f   f   f   f   f   f   pppp     p"},
{"p  f  pp                                                              pp       p"},
{"p     pp  f    f    f     f   f   f   f   f   f   f   f   f   f   f   pp t     p"},
{"p     pp                                                              pp       p"},
{"p  f  pppppp       ppppppppppppp     ppppppppppppppppppppppppppp      pp       p"},
{"p              f   ppppppppppppp     ppppppppppppppppppppppppppp      pp   f   p"},
{"p                  pp                ppp      ppp                     pp       p"},
{"p  f   f   f   f   pp                ppp  f   ppp  f    f    f    f   pp       p"},
{"p                  pp  f   f    f    ppp      ppp                     pp   f   p"},
{"ppppppppppppppppppppp                ppp  f   ppp                              p"},
{"ppppppppppppppppppppppppppppppp                                                p"},
{"p                            pp                                                p"},
{"ppppppppppppppppppppppppppppppp   f   f   f   f    f   f    f    f    f    f   p"},
{"p                            pp                                                p"},
{"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp"},
{"p g    ppp               g                            p                        p"},
{"p      ppp   f                                        p                        p"},
{"p      ppp                                            p   f    f    f      f   p"},
{"p      ppp          f                                 p                        p"},
{"p  f   ppp  f  pp       pppppppppppppppppppppp        p                p       p"},
{"p      ppp     pp                    t                    f    f       p       p"},
{"p      ppp  f  pp                                                      p   f   p"},
{"p  f   ppp     pp   f   f    f     f    f     f           f   f    f   p       p"},
{"p      ppp f   pp                                                      p       p"},
{"p      ppp     pppppppppppppppppppppp      ppppppppppppppppppppppppppppp       p"},
{"p  f   ppp     pppppppppppppppppppppp  f   ppppppppppppppppppppppppppppp   f   p"},
{"p      ppp  f  pppppppppppppppppppppp      p  p  p  f   f g                    p"},
{"p              pp         g            f   p  p  p   f f                       p"},
{"p  f           pp   f                      p  p  p    f                        p"},
{"p           f  pp      f   f    f   f      p  p  p   f f                   f   p"},
{"p              pp                      f   p  p  p  f   f                      p"},
{"p  f        f  pp  f                       p  p  ppppppppppppppppppppppp       p"},
{"p      ppp              pppppppppppp       p  p  ppppppppppppppppppppppp       p"},
{"p      ppp  f       f   pppppppppppp   f   p  p  p                    pp   f   p"},
{"p  f   ppp              p                  p  p  p                    pp       p"},
{"p      ppp  f   f   f   pppppppppppp   f   p  p  p   f     ff     f   pp       p"},
{"p      ppp              p                  p  p  p                    pp       p"},
{"p  f   ppppppppppppppppppppppppppppppppppppppppppp                    pp   f   p"},
{"p                                                      pppppppp       pp       p"},
{"p                                                      pppppppp   f   pp       p"},
{"p  f   f    f     f     f      f      f      f     f                  pp       p"},
{"p                                                                     pp   f   p"},
{"p                                                  f      f       f            p"},
{"pppppppppppppppppppppppppppppppppppppp                                         p"},
{"pppppppppppppppppppppppppppppppppppppp          pppppppppppppppppppppppppppppppp"},
{"p                                                                              p"},
{"p  t                          g                                                p"},
{"p     f      f      f      f      f      f      f      f      f      f      f  p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp"}
};

std::vector<std::string> cenario1 = {
{"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                            ppppp             p"},
{"p           p                    p                           pppp              p"},
{"p           p                    p                          ppppp              p"},
{"p           p                    p                           pppp              p"},
{"p           p                    p                                             p"},
{"p           p                    p                                             p"},
{"p           p                    p                               g             p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                   fffff                      p"},
{"p                                                   ppppp                      p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p               ppppppppppppppppp                  ff                          p"},
{"p                                                                             pp"},
{"p                                                                             pp"},
{"p                                                                             pp"},
{"p                                                                             pp"},
{"p                                                                              p"},
{"p                g                                                             p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                               p                              p"},
{"p                                               p              p               p"},
{"p                                               p              p               p"},
{"p                                  pppppppppppppp              p               p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p           ppp                                                                p"},
{"p           ppp                                                                p"},
{"p          ppppp                                                               p"},
{"p                                                                              p"},
{"p                                      t                                       p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                             ppppppppp                        p"},
{"p        p                                    pppppppppp                       p"},
{"p        p                                    pppppppp                         p"},
{"p        p                                                                     p"},
{"p        p                                                                     p"},
{"p        pppppppppp                                                            p"},
{"p                                                                              p"},
{"p                                        pppppppppp                            p"},
{"p                                        pppppppppp   t             g          p"},
{"p                                                                              p"},
{"p           ppppppppppppp                                                      p"},
{"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp"}
};

std::vector<std::string> cenario2= {
{"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp"},
{"p                                                            p                 p"},
{"p                                                            p                 p"},
{"p                                                            p                 p"},
{"p                                                                              p"},
{"p           pp p p p p p p p p p p                                             p"},
{"p           p                    p                                             p"},
{"p           p      g             p                                             p"},
{"p           p                    p                                             p"},
{"p           p                    p                           p                 p"},
{"p           p                    p                           p                 p"},
{"p           p                    p                           p                 p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                    ggg                                       p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p               ppppppppppppppppp                                              p"},
{"p               p               p                                              p"},
{"p               p               p                                              p"},
{"p               ppppppppppppppppp                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                 ppppppppppppppp                              p"},
{"p                                p t                                           p"},
{"p                               p                                              p"},
{"p                              p                                               p"},
{"p                             p                        p                       p"},
{"p                            p                         pp                      p"},
{"p                           p                          ppp                     p"},
{"p                          p                           pppp                    p"},
{"p                         p                                                    p"},
{"p                        p                                                     p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p        p                                             pppp                    p"},
{"p        p                                             ppp                     p"},
{"p        p                                             pp                      p"},
{"p        p                                             p                       p"},
{"p        pppppppppp                                                            p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp"}
};

