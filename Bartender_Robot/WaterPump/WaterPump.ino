
#include <Servo.h>
int bomba1 = 9;
boolean toggle = true;

void setup() {
  Serial.begin (9600);
  pinMode (bomba1, OUTPUT);

}

void loop() {
  
  digitalWrite (bomba1, HIGH);
  delay (40000);
  digitalWrite (bomba1, LOW);
  delay (999000);  
      
}
