
#include <Servo.h>

Servo servito;
Servo hielo;
int bomba1 = 9;
int bomba2 = 8;
int pot = A3;
int stpot = 0;
int var = 0;

void setup() {
  Serial.begin (9600);
  hielo.attach(10);
  servito.attach(4); // tiene que ser en una entrada de "ondita"
pinMode (bomba1, OUTPUT);
  
pinMode (bomba2, OUTPUT);
 
 
}

void loop() {

  stpot = analogRead(pot)/4;
 if(stpot > 200){

  var = Serial.read();
  
  if (var == 'a'){//refresco 1
  hielo.write(0);// inicia en posicion 0
  delay (1000);
  hielo.write(110);
  delay(1000);
  
  servito.write(0);
  delay(4000);
  servito.write(80);
  delay(4000);

  digitalWrite (bomba1, HIGH);
  delay (3000);
  digitalWrite (bomba1, LOW);
  delay (1000);
  }

  if (var == 'b'){//refresco 2
  hielo.write(0);// inicia en posicion 0
  delay (1000);
  hielo.write(90);
  delay(1000);
  hielo.write(0);

  servito.write(0);
  delay(4000);
  servito.write(160);
  delay(4000);

  digitalWrite (bomba2, HIGH);
  delay (3000);
  digitalWrite (bomba2, LOW);
  delay (1000);
  }
  
 }

  
}
