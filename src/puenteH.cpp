 #include <Arduino.h>
 
 int enA=3;  //Pin para controlar la velocidad
 int in1=4;  //Terminal A del motor derecho
 int in2=2; //terminal в del motor derecho

 int enB =6; //Pin para controlar la velocidad
 int in3=5;  //terminal A del motor izquierdo
 int in4=7; //terminal в del motor izquierdo
  
 void adelante()
  {
    analogWrite(enA,255);
    analogWrite(enB,255);
    //Control del motor Derecho
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    //Control del motor Izquierdo
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
  }
  
  void atras()
  {
    analogWrite(enA,200);
    analogWrite(enB,255);
    //Control del motor Derecho
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    //Control del motor Izquierdo
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
  }
void izquierda()
{
  analogWrite(enA,110);
  analogWrite(enB,110);
  //Control del motor Derecho
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  //Control del motor Izquierdo
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void derecha()
{
  analogWrite(enA,74);
  analogWrite(enB,74);
  //Controla la velocidad de motor con valores de 0 a 255
  //Control del motor Derecho
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  //Control del motor Izquierdo
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void freno()
{
  analogWrite(enA,255);
  analogWrite(enB,255);
  //Controla la velocidad de motor con valores de 0 a 255
  //Control del motor Derecho
  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
  //Control del motor Izquierdo
  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);

}
void atrasDer()
{
  analogWrite(enA,150);
  analogWrite(enB,255);
  //Controla la velocidad de motor con valores de 0 a 255
  //Control del motor Derecho
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  //Control del motor Izquierdo
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void OFF()
{
  analogWrite(enA,0);
  analogWrite(enB,0);
  //Controla la velocidad de motor con valores de 0 a 255
  //Control del motor Derecho
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  //Control del motor Izquierdo
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

}