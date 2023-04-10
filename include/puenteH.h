#ifndef puenteH_h
#define puenteH_h
#include <Arduino.h>

class Motor
{
  private:
    int _ENA; //Pin para controlar la velocidad
    int _IN1; //Terminal A del motor derecho
    int _IN2; //terminal в del motor derecho
    int _ENB; //Pin para controlar la velocidad
    int _IN3; //terminal A del motor izquierdo
    int _IN4; //terminal в del motor izquierdo
  public:
    Motor(int ENA, int IN1, int IN2, int ENB, int IN3, int IN4); //Constructor
    void adelante();
    void atras();
    void izquierda();
    void derecha();
    void freno();
  
};

#endif // puenteH_h
