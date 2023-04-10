#ifndef puenteH_h
#define puenteH_h

class puenteH
{
  private:
    int _ENA; //Pin para controlar la velocidad
    int _IN1; //Terminal A del motor derecho
    int _IN2; //terminal в del motor derecho
    int _ENB; //Pin para controlar la velocidad
    int _IN3; //terminal A del motor izquierdo
    int _IN4; //terminal в del motor izquierdo
  public:
    puenteH(int ENA, int IN1, int IN2, int ENB, int IN3, int IN4); //Constructor
    void adelante(int velocidad1, int velocidad2);
    void atras(int velocidad1, int velocidad2);
    void izquierda();
    void derecha();
    void freno();
    void atrasDer();
    void atrasIz();
    void OFF();
  
};

#endif // puenteH_h
