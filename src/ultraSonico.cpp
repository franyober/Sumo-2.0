#include <Arduino.h>

int const trig1=32;
int const Echo1=35;

int const trig2=26;
int const Echo2=25;

int const trig3=5;
int const Echo3=17;

int distancia1,distancia2,distancia3;

String obtainDistance(int num)
{
    String distance;
    switch(num)
    {
        case 1:
            distance = String(distancia1);
            break;
        case 2:
            distance = String(distancia2);
            break;
        case 3:
            distance = String(distancia3);
            break;
        default:
            distance = String("0S");
            break;
    }
    return distance;
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

void Ultrasonicos(void *parameter)
{
  pinMode (trig1, OUTPUT); //Salidad desde Arduino
  pinMode (Echo1, INPUT); //Entrada de datos desde Ultrasonico

  pinMode (trig2, OUTPUT); //Salidad desde Arduino
  pinMode (Echo2, INPUT); //Entrada de datos desde Ultrasonico

  pinMode (trig3, OUTPUT); //Salidad desde Arduino
  pinMode (Echo3, INPUT); //Entrada de datos desde Ultrasonico
              
  while(1)
  {
    distancia1=getDistance(trig1,Echo1);
    distancia2=getDistance(trig2,Echo2);
    distancia3=getDistance(trig3,Echo3);

    Serial.print(distancia1);Serial.print(",");
    Serial.print(distancia2);Serial.print(",");
    Serial.print(distancia3);Serial.print(",");
    Serial.println();

    vTaskDelay(1/portTICK_PERIOD_MS);
  }
}

