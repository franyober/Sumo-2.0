#include <Arduino.h>

#define ENA 3  //Pin para controlar la velocidad
#define IN1 4  //Terminal A del motor derecho
#define IN2 2 //terminal в del motor derecho
#define ENB 6 //Pin para controlar la velocidad
#define IN3 5  //terminal A del motor izquierdo
#define IN4 7 //terminal в del motor izquierdo
  
 void adelante()
  {
    analogWrite(ENA,255);
    analogWrite(ENB,255);
    //Control del motor Derecho
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    //Control del motor Izquierdo
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
  
  void atras()
  {
    analogWrite(ENA,200);
    analogWrite(ENB,255);
    //Control del motor Derecho
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    //Control del motor Izquierdo
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }
void izquierda()
{
  analogWrite(ENA,110);
  analogWrite(ENB,110);
  //Control del motor Derecho
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  //Control del motor Izquierdo
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void derecha()
{
  analogWrite(ENA,74);
  analogWrite(ENB,74);
  //Controla la velocidad de motor con valores de 0 a 255
  //Control del motor Derecho
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  //Control del motor Izquierdo
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void freno()
{
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  //Controla la velocidad de motor con valores de 0 a 255
  //Control del motor Derecho
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  //Control del motor Izquierdo
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);

}
void atrasDer()
{
  analogWrite(ENA,150);
  analogWrite(ENB,255);
  //Controla la velocidad de motor con valores de 0 a 255
  //Control del motor Derecho
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  //Control del motor Izquierdo
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void OFF()
{
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  //Controla la velocidad de motor con valores de 0 a 255
  //Control del motor Derecho
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  //Control del motor Izquierdo
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

}