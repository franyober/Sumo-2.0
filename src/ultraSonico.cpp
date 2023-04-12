#include <Arduino.h>

int const trig1=18;
int const Echo1=19;

int const trig2=5;
int const Echo2=17;

int const trig3=16;
int const Echo3=4;

int distancia1,distancia2,distancia3;


String obtainDistance(int num)
{
  switch(num)
  {
    case 1:
      return String(distancia1);
    case 2:
      return String(distancia2);
    case 3:
      return String(distancia3);
    default :
      return String(0);
  }
}

int getDistance(int trig, int Echo)
{
  long duracion;int distancia;
  
  digitalWrite(trig,LOW);//Apagando el ultrasonico
  delayMicroseconds(4);

  digitalWrite(trig,HIGH);//Activando el ultrasonico
  delayMicroseconds(19);  // No se si se pueda poner delays en funciones que se llama en una tarea

  digitalWrite(trig,LOW);
  duracion=pulseIn(Echo,HIGH); 
  
  duracion=duracion/2;
  distancia=duracion/29;

  return distancia;
}

void Ultrasonico1(void *parameter)
{
  pinMode (trig1, OUTPUT); //Salidad desde Arduino
  pinMode (Echo1, INPUT); //Entrada de datos desde Ultrasonico

  while(1)
  {
    distancia1=getDistance(trig1,Echo1);
    vTaskDelay(20/portTICK_PERIOD_MS);
  }
}

void Ultrasonico2(void *parameter)
{
  pinMode (trig2, OUTPUT); //Salidad desde Arduino
  pinMode (Echo2, INPUT); //Entrada de datos desde Ultrasonico
  while(1)
  {
    distancia2=getDistance(trig2,Echo2);
    vTaskDelay(20/portTICK_PERIOD_MS);
  }
}

void Ultrasonico3(void *parameter)
{
  pinMode (trig3, OUTPUT); //Salidad desde Arduino
  pinMode (Echo3, INPUT); //Entrada de datos desde Ultrasonico
  while(1)
  {
    distancia3=getDistance(trig3,Echo3);
    vTaskDelay(20/portTICK_PERIOD_MS);
  }
}