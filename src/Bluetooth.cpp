#include "puenteH.h"
#include "ultraSonico.h"

#include <BluetoothSerial.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


BluetoothSerial SerialBT;

String opc="";

void bluetoothTask(void *parameter) {

  Serial.begin(115200);
  SerialBT.begin("ESP32test");
  Serial.println("The device started, now you can pair it with bluetooth!");

  while(1){
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    opc = SerialBT.readStringUntil('\n');
    Serial.write("Cell: ");
    Serial.println(opc);
    }
    vTaskDelay(20/portTICK_PERIOD_MS);
    
    if(opc=="adelante"){
      Serial.println("se escribio adelante");
    }

  }  


}