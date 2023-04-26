#include <ultraSonico.h>
#include <puenteH.h>

extern int distancia1,distancia2,distancia3;
extern puenteH motor;

void Estrategia1(void * parameter) {
  while(1) {

    if(distancia1<40 && distancia1>3){
        motor.adelante(100,100);
    }
    if(distancia2<40 && distancia2>3){
        motor.derecha();
    }
    if(distancia3<40 && distancia3>3){
        motor.izquierda();
    }

  }
}

void Estrategia2(void * parameter) {
  while(1) {

    //Aqui va la estrategia 2

  }
}

void Estrategia3(void * parameter) {
  while(1) {

    //Aqui va la estrategia 3
  }
}