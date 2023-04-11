#include "puenteH.h"
#include "ultraSonico.h"

#include <BluetoothSerial.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


BluetoothSerial SerialBT;

char opc = 'z'; // Nos da la opcion de que hacer para el menú
char selectedSensor = 'z';// Nos da la opcion de cual sensor se está presentando

void bluetoothTask(void *parameter) {

  Serial.begin(115200);
  SerialBT.begin("ESP32test");
  Serial.println("The device started, now you can pair it with bluetooth!");

  while(1){
  // if (Serial.available()) {
  //   SerialBT.write(Serial.read()); //Usar en caso de que quisieramos escribir desde el monitor serial
  // }
  if (SerialBT.available()) {
    opc = SerialBT.read();
    }
    vTaskDelay(20/portTICK_PERIOD_MS);
  }


}

void writeBluetooth(String msg){
  SerialBT.println(msg);
}

int Getopc(){
  return atoi(&opc);
}