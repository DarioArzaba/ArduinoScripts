
#include <Servo.h>
Servo hielo;

void setup() {
  Serial.begin (9600);
  hielo.attach(5);
}

void loop() {
  
      hielo.write(30);
      delay(1000);
      hielo.write(110);
      delay (99000);
  
}

