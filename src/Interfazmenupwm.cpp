#include <puenteH.h>
#include <Bluetooth.h>
#include  <BluetoothSerial.h>

BluetoothSerial SerialBT;

int var1=0,var2=0;
char c;

void setup(){
  Serial.begin(9600);
}

void loop() {
  while (SerialBT.available()>0){
    c= SerialBT.read();
    if(c=='A'){
      var1=SerialBT.parseInt();
    }
    if(c=='B'){
      var2=SerialBT.parseInt();
    }
SerialBT.println(var1);
SerialBT.println(var1);
SerialBT.println();
  }
}