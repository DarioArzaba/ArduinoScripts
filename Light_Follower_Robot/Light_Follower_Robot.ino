//Girasol con servo y dos fotoresistencias

#include <Servo.h>

Servo myservo;
int servoPos = 0;
int inputPhotoLeft = A1;
int inputPhotoRight = A0;
int Left = 0; // Store readings from the photoresistors.
int Right = 0; // Store readings from the photoresistors.
int deadZone = 20;

unsigned long  printInterval = 1000;
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;

void setup()  {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop()
{

Left = analogRead(inputPhotoLeft);
Right = analogRead(inputPhotoRight);  

currentMillis = millis();
if ((currentMillis - previousMillis ) >= printInterval){
  previousMillis = currentMillis;
  Serial.print("Lado izquierdo: "); Serial.println(Right);
  Serial.print("Lado derecho: "); Serial.println(Left);
  Serial.println();
}

//if (abs(Left-Right) > 100) {
  
  if (Left > (Right + deadZone)) {
    if (servoPos < 179) {    
      servoPos++;
      myservo.write(servoPos);
    }
  }
  
  if (Right > (Left + deadZone)) {
    if (servoPos > 1){
      servoPos -= 1;
      myservo.write(servoPos);
    }
  }
  
//}

  delay(4);
}
