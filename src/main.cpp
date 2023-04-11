#include <Arduino.h>
#include "puenteH.h"
#include "ultraSonico.h"
#include "Bluetooth.h"

//Nucleos de la ESP32s

static const BaseType_t xCore1 = 1;
static const BaseType_t xCore0 = 0; 


//Motor pines
puenteH motor(32,33,25,26,27,14); // Usar pines compatibles con la esp32


enum Opciones {
  OFF,  //0
  Adelante, //1
  Atras,//2
  Izquierda,//3
  Derecha,//4
  Inicio,//5
  Ultra1,//6
  Ultra2,//7
  Ultra3//8
};

Opciones caso;


void setup() {

  xTaskCreatePinnedToCore(
    bluetoothTask,   /* Task function. */
    "bluetoothTask",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    NULL,        /* Task handle to keep track of created task */
    xCore0);     /* pin task to core 0 */

  xTaskCreatePinnedToCore(
    Ultrasonico1,   /* Task function. */
    "Ultrasonico1",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    NULL,        /* Task handle to keep track of created task */
    xCore1);     /* pin task to core 1 */

  xTaskCreatePinnedToCore(
    Ultrasonico2,   /* Task function. */
    "Ultrasonico2",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    NULL,        /* Task handle to keep track of created task */
    xCore1);     /* pin task to core 1 */

  xTaskCreatePinnedToCore(
    Ultrasonico3,   /* Task function. */
    "Ultrasonico3",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    NULL,        /* Task handle to keep track of created task */
    xCore1);     /* pin task to core 1 */


}

void loop() {

  caso = (Opciones)Getopc();

  switch(caso) {
    case Inicio:
    writeBluetooth("Inicio");

      break;
    case Adelante:
    writeBluetooth("Adelante");

    motor.adelante(110,110);
      break;
    case Atras:
    writeBluetooth("Atras");

    motor.atras(110,110);
      break;
    case Izquierda:
    writeBluetooth("Izquierda");

    motor.izquierda();
      break;
    case Derecha:
    writeBluetooth("Derecha");

    motor.derecha();
      break;
    case OFF:
    writeBluetooth("Stop");

    motor.OFF();
      break;
    case Ultra1:
    writeBluetooth("Ultra1");


      break;
    case Ultra2:
    writeBluetooth("Ultra2");


      break;
    case Ultra3:
    writeBluetooth("Ultra3");


      break;
    default:
    writeBluetooth("Justo le pegaste al nueve");
      break;
  }
  vTaskDelay(1000/portTICK_PERIOD_MS);

}

