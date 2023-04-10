#include <Arduino.h>

#include "puenteH.h"
#include "ultraSonico.h"

void setup() {
  //Motor pines
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);

  pinMode (trig1, OUTPUT); //Salidad desde Arduino
  pinMode (Echo1, INPUT); //Entrada de datos desde Ultrasonico

}

void loop() {

  if(getDistance(trig1,Echo1)<40 and getDistance(trig1,Echo1)>0)
  {

    freno();
    adelante();
    delay(100);

  }
  else
  {
    derecha();
  }

  delay(25);

}