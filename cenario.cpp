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

std::vector<std::string> cenario0 = {
{"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp"},
{"p         p              p      p                                              p"},
{"p         p              p      p                                              p"},
{"p         p              p      p                                              p"},
{"p   f     p   f          p      p                                              p"},
{"p         p                            pppppppppppppppppppppppp     pppppppppppp"},
{"p         p                            p                            p          p"},
{"p         p                            p                            p          p"},
{"p   f     p   f                        p   f         f           f  p          p"},
{"p         p       pppppppppppppppppppppp                                       p"},
{"p   f     p       ppp                  ppppppppppppppppppppp                   p"},
{"p         p       ppp                                                          p"},
{"p         p       ppp        f      f                                          p"},
{"p         p       ppp                                                          p"},
{"p   f     p   f   ppp                                                          p"},
{"p                 ppp                                                          p"},
{"p                 ppp                                                          p"},
{"p         f       ppp                f                                         p"},
{"p                 ppp                                                          p"},
{"pppppppppppppppppppppppppppp                                                   p"},
{"pppppppppppppppppppppppppppppppp               f        f         f       f    p"},
{"pppppppppppppppppppppppppppppppppppp                                           p"},
{"pppppppppppppppppppppppppppppppppppppppp                                       p"},
{"ppppppppppppppppppppppppppppppppppppppppppppp                                  p"},
{"pp                                                                             p"},
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

