#ifndef H_VEICULO
#define H_VEICULO

class Veiculo
{
  protected:
    float x; 
    float y;
    float vx; // LED/seg
    float vy; // LED/seg
    int comprimento;

  public:
    Veiculo(float xi, float yi, float vxi, float vyi, int comprimento);
    ~Veiculo();

    void mover(float dx, float dy);
    
    // Sets e gets
    void setX(float x) {this->x = x;}
    void setY(float y) {this->y = y;}
    void setVX(float vx) {this->vx = vx;}
    void setVY(float vy) {this->vy = vy;}
    void setComprimento(int comprimento) {this->comprimento = comprimento;}
    float getX() {return x;}
    float getY() {return y;}
    float getVX() {return vx;}
    float getVY() {return vy;}
    int getComprimento() {return comprimento;}
};

#endif
