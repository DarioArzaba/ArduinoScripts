
#include <Servo.h>
Servo servito;

void setup() {
  servito.attach(2);
}

void loop() {
  
      servito.write(0);
      delay(9000);
      servito.write(90);
      delay(95000);
    
}
