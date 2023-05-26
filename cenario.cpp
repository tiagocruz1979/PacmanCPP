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

std::vector<sf::Vector2f>& getDestinoPortal(int index)
{
    static std::vector<sf::Vector2f> res;
    if(index == 1)
    {
    }
    else if(index == 2)
    {
        res.push_back(sf::Vector2f(20.f,20.f));
    }
    else
    {
        res.push_back(sf::Vector2f(20.f,20.f));
        res.push_back(sf::Vector2f(200.f,200.f));
        res.push_back(sf::Vector2f(200.f,20.f));
    }

    return res;
}

std::vector<std::string> cenario0 = {
{"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp"},
{"p     pp                        ppp                                            p"},
{"p     pp                        ppp                                            p"},
{"p     pp  f  f  f  f     fff    ppp  f  f    f    f    f   f  f   f  f  f  f   p"},
{"p  f  pp                        ppp                                            p"},
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
{"p      ppp                        t                   p                        p"},
{"p  f   ppp   f                                        p                        p"},
{"p      ppp                                            p   f    f    f      f   p"},
{"p      ppp          f                                 p                        p"},
{"p  f   ppp  f  pp       pppppppppppppppppppppp        p                p       p"},
{"p      ppp     pp                                         f    f       p       p"},
{"p      ppp  f  pp                                                      p   f   p"},
{"p  f   ppp     pp   f   f    f     f    f     f           f   f    f   p       p"},
{"p      ppp f   pp                                                      p       p"},
{"p      ppp     pppppppppppppppppppppp      ppppppppppppppppppppppppppppp       p"},
{"p  f   ppp     pppppppppppppppppppppp  f   ppppppppppppppppppppppppppppp   f   p"},
{"p      ppp  f  pppppppppppppppppppppp      p  p  p  f   f                      p"},
{"p              pp                      f   p  p  p   f f                       p"},
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
{"p  t                                                                           p"},
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
{"p                                                            oooo              p"},
{"p           p                    p                           oooo              p"},
{"p           p                    p                           oooo              p"},
{"p           p                    p                           oooo              p"},
{"p           p                    p                                             p"},
{"p           p                    p                                             p"},
{"p           p                    p                                             p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                   ooo                        p"},
{"p                                                   ooo                        p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p               ppppppppppppppppp                                              p"},
{"p                                                                             op"},
{"p                                                                             op"},
{"p                                                                             op"},
{"p                                                                             op"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                               o                              p"},
{"p                                               o              o               p"},
{"p                                               o              o               p"},
{"p                                  pppppppppppppp              o               p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p           ooo                                                                p"},
{"p           ooo                                                                p"},
{"p           ooo                                                                p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                              oooo                            p"},
{"p        p                                     oooo                            p"},
{"p        p                                     oooo                            p"},
{"p        p                                                                     p"},
{"p        p                                                                     p"},
{"p        pppppppppp                                                            p"},
{"p                                                                              p"},
{"p                                         ooooo                                p"},
{"p                                         ooooo                                p"},
{"p                                                                              p"},
{"p           oooo                                                               p"},
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
{"p           p                    p                                             p"},
{"p           p                    p                                             p"},
{"p           p                    p                           p                 p"},
{"p           p                    p                           p                 p"},
{"p           p                    p                           p                 p"},
{"p                                                                              p"},
{"p                                                                              p"},
{"p                                    ooo                                       p"},
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
{"p                                p                                             p"},
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

