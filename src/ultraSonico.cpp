#include <Arduino.h>

int getDistance(int trig, int Echo)
{
  long duracion;int distancia;
  
  digitalWrite(trig,LOW);//Apagando el ultrasonico
  delayMicroseconds(4);

  digitalWrite(trig,HIGH);//Activando el ultrasonico
  delayMicroseconds(19);

  digitalWrite(trig,LOW);
  duracion=pulseIn(Echo,HIGH);
  
  duracion=duracion/2;
  distancia=duracion/29;

  return distancia;
}