#ifndef H_VEICULO
#define H_VEICULO

#include "Pista.hpp"

class Veiculo
{
  protected:
    float x; 
    float y;
    float vx; // LED/seg
    float vy; // LED/seg
    int comprimento;

  public:
    Veiculo(float xi = 3.0, float yi = 0.0, int comprimento = 1);
    ~Veiculo();

    void mover(float dt); // Move-se de acordo com o tempo
    virtual void verificarColisao(Pista *pPista, float dt) = 0; // Colisão com a pista
    
    // Sets
    void setX(float x) {this->x = x;}
    void setY(float y) {this->y = y;}
    void setVX(float vx) {this->vx = vx;}
    void setVY(float vy) {this->vy = vy;}
    void setComprimento(int comprimento) {this->comprimento = comprimento;}
    
    // Gets
    float getX() {return x;}
    float getY() {return y;}
    float getVX() {return vx;}
    float getVY() {return vy;}
    int getComprimento() {return comprimento;}
};

#endif
