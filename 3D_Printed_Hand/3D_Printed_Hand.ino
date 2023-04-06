#include <Servo.h>

Servo UnoDos ;
Servo TresCuatro ;
int pinEntrada = A0;
int valorSensorBrazo = 0;

void setup() {
    UnoDos.attach(9);
    TresCuatro.attach(6);
    Serial.begin(9600);
    pinMode(pinEntrada, INPUT);
}

void loop() {

  valorSensorBrazo = analogRead(pinEntrada);
  Serial.print("Sensor = ");
 
  Serial.println(valorSensorBrazo);
  
   if (valorSensorBrazo > 200){
    UnoDos.write(10);
    TresCuatro.write(10);
    delay(800);
  } else {
    UnoDos.write(180);
    TresCuatro.write(180);
    delay(800);
  }
  
}
