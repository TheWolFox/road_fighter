#include  "Veiculo.h"

Veiculo::Veiculo(int xi, int yi, int vxi, int comprimento, int id) {
    inicializar(xi,yi,vxi);
    setComprimento(comprimento);
    this->id = id;
}

Veiculo::~Veiculo() {

}

void Veiculo::inicializar(int xi, int yi, int v) {
    setCoordenadas(xi, yi);
    setVelocidade(v);
} 