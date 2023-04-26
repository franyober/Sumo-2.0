#include "puenteH.h"
#include "ultraSonico.h"

#include <BluetoothSerial.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


BluetoothSerial SerialBT;

char opc[2] = {'0', '0'}; // Nos da la opcion de que hacer para el menú

void bluetoothTask(void *parameter) {
  Serial.begin(115200);
  SerialBT.begin("ESP32test");
  Serial.println("The device started, now you can pair it with bluetooth!");

  while(1){

    if (SerialBT.available() > 0) {
      if (SerialBT.available() == 1) {
        opc[1] = '\0';
        opc[0] = SerialBT.read();
      }
      else if (SerialBT.available() == 2) {
        SerialBT.readBytes(opc, 2);
      }
    }
    vTaskDelay(20/portTICK_PERIOD_MS);
  }
}

void writeBluetooth(String msg){
  SerialBT.println(msg);
}

int Getopc() {
  return atoi(opc);
}