#include <Arduino.h>
#include "puenteH.h"

// #define ENA 3  //Pin para controlar la velocidad
// #define IN1 4  //Terminal A del motor derecho
// #define IN2 2 //terminal в del motor derecho
// #define ENB 6 //Pin para controlar la velocidad
// #define IN3 5  //terminal A del motor izquierdo
// #define IN4 7 //terminal в del motor izquierdo
  

puenteH::puenteH(int ENA, int IN1, int IN2, int ENB, int IN3, int IN4)
{
  pinMode (IN1, OUTPUT);
  _IN1=IN1;
  pinMode (IN2, OUTPUT);
  _IN2=IN2;
  pinMode (IN3, OUTPUT);
  _IN3=IN3;
  pinMode (IN4, OUTPUT);
  _IN4=IN4;
  pinMode (ENA, OUTPUT);
  _ENA=ENA;
  pinMode (ENB, OUTPUT);
  _ENB=ENB;
}

 void puenteH::adelante(int velocidad1, int velocidad2)
  {
    analogWrite(_ENA,velocidad1); //Controla la velocidad de motor1 con valores de 0 a 255
    analogWrite(_ENB,velocidad2); //Controla la velocidad de motor2 con valores de 0 a 255
    //Control del motor Derecho Adelante
    digitalWrite(_IN1,HIGH);
    digitalWrite(_IN2,LOW);
    //Control del motor Izquierdo Adelante
    digitalWrite(_IN3,HIGH);
    digitalWrite(_IN4,LOW);
  }

  void puenteH::atras(int velocidad1, int velocidad2)
  {
    analogWrite(_ENA,velocidad1);
    analogWrite(_ENB,velocidad2);
    //Control del motor Derecho
    digitalWrite(_IN1,LOW);
    digitalWrite(_IN2,HIGH);
    //Control del motor Izquierdo
    digitalWrite(_IN3,LOW);
    digitalWrite(_IN4,HIGH);
  }

  void puenteH::izquierda()
  {
    analogWrite(_ENA,110);
    analogWrite(_ENB,110);
    //Control del motor Derecho
    digitalWrite(_IN1,LOW);
    digitalWrite(_IN2,HIGH);
    //Control del motor Izquierdo
    digitalWrite(_IN3,HIGH);
    digitalWrite(_IN4,LOW);
  }  

  void puenteH::derecha()
  {
    analogWrite(_ENA,110);
    analogWrite(_ENB,110);
    //Control del motor Derecho
    digitalWrite(_IN1,HIGH);
    digitalWrite(_IN2,LOW);
    //Control del motor Izquierdo
    digitalWrite(_IN3,LOW);
    digitalWrite(_IN4,HIGH);
  }

  void puenteH::freno()
  {
    analogWrite(_ENA,255);
    analogWrite(_ENB,255);
    //Control del motor Derecho
    digitalWrite(_IN1,HIGH);
    digitalWrite(_IN2,HIGH);
    //Control del motor Izquierdo
    digitalWrite(_IN3,HIGH);
    digitalWrite(_IN4,HIGH);
  }

  void puenteH::atrasIz()
  {
    analogWrite(_ENA,255);
    analogWrite(_ENB,150);
    //Controla la velocidad de motor con valores de 0 a 255
    //Control del motor Derecho
    digitalWrite(_IN1,LOW);
    digitalWrite(_IN2,HIGH);
    //Control del motor Izquierdo
    digitalWrite(_IN3,HIGH);
    digitalWrite(_IN4,LOW);
  }

  void puenteH::atrasDer()
  {
    analogWrite(_ENA,150);
    analogWrite(_ENB,255);
    //Controla la velocidad de motor con valores de 0 a 255
    //Control del motor Derecho
    digitalWrite(_IN1,LOW);
    digitalWrite(_IN2,HIGH);
    //Control del motor Izquierdo
    digitalWrite(_IN3,LOW);
    digitalWrite(_IN4,HIGH);
  }

  void puenteH::OFF()
  {
    analogWrite(_ENA,0);
    analogWrite(_ENB,0);
    //Controla la velocidad de motor con valores de 0 a 255
    //Control del motor Derecho
    digitalWrite(_IN1,LOW);
    digitalWrite(_IN2,LOW);
    //Control del motor Izquierdo
    digitalWrite(_IN3,LOW);
    digitalWrite(_IN4,LOW);
  }
