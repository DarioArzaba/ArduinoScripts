
#include <Servo.h>
Servo servito;


void setup() {
  Serial.begin (9600);
  servito.attach(6);


}



void loop() {

   
    servito.write(0);
      delay(9000);
      servito.write(90);
      delay(1000);

}
