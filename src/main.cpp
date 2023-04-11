#include <Arduino.h>
#include "puenteH.h"
#include "ultraSonico.h"
#include "Bluetooth.h"

//Nucleos de la ESP32s

static const BaseType_t xCore1 = 1;
static const BaseType_t xCore0 = 0; 


//Motor pines
puenteH motor(3,4,2,6,5,7);

void setup() {
  pinMode (trig1, OUTPUT); //Salidad desde Arduino
  pinMode (Echo1, INPUT); //Entrada de datos desde Ultrasonico

  xTaskCreatePinnedToCore(
    bluetoothTask,   /* Task function. */
    "bluetoothTask",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    NULL,        /* Task handle to keep track of created task */
    xCore0);     /* pin task to core 0 */

  }

void loop() {

}