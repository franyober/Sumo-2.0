#include <Arduino.h>
#include "puenteH.h"
#include "ultraSonico.h"
#include "Bluetooth.h"

//Nucleos de la ESP32s

static const BaseType_t xCore1 = 1;
static const BaseType_t xCore0 = 0; 


//Motor pines
puenteH motor(14,12,13,15,2,0); // Usar pines compatibles con la esp32


enum Opciones {
  OFF,  //0
  Adelante, //1
  Atras,//2
  Izquierda,//3
  Derecha,//4
  Inicio,//5
  Ultra1,//6
  Ultra2,//7
  Ultra3,//8
  caso9,
  caso10,
  caso11
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
    Ultrasonicos,   /* Task function. */
    "Ultrasonico1",     /* name of task. */
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

    motor.adelante(110,110);//motor.adelante(a,b)
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
    writeBluetooth("Ultra1 ");
    writeBluetooth(obtainDistance(1));

      break;
    case Ultra2:
    writeBluetooth("Ultra2");
    writeBluetooth(obtainDistance(2));

      break;
    case Ultra3:
    writeBluetooth("Ultra3");
    writeBluetooth(obtainDistance(1));

      break;
    case caso9:
    writeBluetooth("nueve");
      break;
    case caso10:
    writeBluetooth("diez");
      break;
    case caso11:
    writeBluetooth("once");
      break;
    default:
    writeBluetooth("default");
      break;
  }
  vTaskDelay(100/portTICK_PERIOD_MS);

}

