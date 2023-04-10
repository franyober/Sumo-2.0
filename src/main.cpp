#include <Arduino.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#include "puenteH.h"
#include "ultraSonico.h"
#include "Bluetooth.h"

//Nucleos de la ESP32s

static const BaseType_t xCore1 = 1;
static const BaseType_t xCore0 = 0; 

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