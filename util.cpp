#include "util.hpp"

bool verificarInterseccao(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
    // Verificar sobreposição nas coordenadas x
//    bool sobreposicaoX = (x1 >= x2 && x1 <= x2 + w2) || (x2 >= x1 && x2 <= x1 + w1);
    float tolerancia = 0.1f;
    x1+=tolerancia;
    y1+=tolerancia;
    w1-=2*tolerancia;
    h1-=2*tolerancia;
    x2+=tolerancia;
    y2+=tolerancia;
    w2-=2*tolerancia;
    h2-=2*tolerancia;

    bool sobreposicaoX = (x1 >= x2 && x1 <= x2 + w2) || (x2 >= x1 && x2 <= x1 + w1);

    // Verificar sobreposição nas coordenadas y
//    bool sobreposicaoY = (y1 >= y2 && y1 <= y2 + h2) || (y2 >= y1 && y2 <= y1 + h1);
    bool sobreposicaoY = (y1 >= y2 && y1 <= y2 + h2) || (y2 >= y1 && y2 <= y1 + h1);

    // Se houver sobreposição nas coordenadas x e y, os retângulos se interceptam
    return sobreposicaoX && sobreposicaoY;
}
