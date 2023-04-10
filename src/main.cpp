#include <Arduino.h>
#include "puenteH.h"
#include "ultraSonico.h"

void setup() {
  //Motor pines
  puenteH motor(3,4,2,6,5,7);

  pinMode (trig1, OUTPUT); //Salidad desde Arduino
  pinMode (Echo1, INPUT); //Entrada de datos desde Ultrasonico

}

void loop() {

  if(getDistance(trig1,Echo1)<40 and getDistance(trig1,Echo1)>0)
  {
    motor.freno();
    motor.adelante(255,255);
    delay(100);
  }
  else
  {
    motor.derecha();
  }

  delay(25);

}