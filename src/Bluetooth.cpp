#include <BluetoothSerial.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


BluetoothSerial SerialBT;
void bluetoothTask(void *parameter) {

  Serial.begin(115200);
  SerialBT.begin("ESP32test");
  Serial.println("The device started, now you can pair it with bluetooth!");

  while(1){
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write("Cell: ");
    Serial.write(SerialBT.read());
    Serial.write("\n");
    }
    vTaskDelay(100/portTICK_PERIOD_MS);


  }  

}