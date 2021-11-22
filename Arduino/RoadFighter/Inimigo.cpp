#include "Inimigo.hpp"

Inimigo::Inimigo(float xi, float yi, float vxi, float vyi, float danoTempo, float danoPonto, int comprimento) :
    Veiculo(xi, yi, vxi, vyi, comprimento),
    danoPonto(danoPonto),
    danoTempo(danoTempo)
{

}

Inimigo::~Inimigo()
{

}
