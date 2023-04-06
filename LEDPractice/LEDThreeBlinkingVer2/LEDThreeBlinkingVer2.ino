/*
Programa de parpadear LEDS externos para 3
 */

int primerLED = 8;
int segundoLED = 10;
int tercerLED = 12;

void setup(){
  pinMode(primerLED, OUTPUT);
  pinMode(segundoLED, OUTPUT);
  pinMode(tercerLED, OUTPUT);
}

void loop(){
  digitalWrite(primerLED, HIGH);
 
  digitalWrite(segundoLED, LOW);
  
  digitalWrite(tercerLED, HIGH);
  delay(1000);
  
  digitalWrite(primerLED, LOW);
  
  digitalWrite(segundoLED, HIGH);
  
  digitalWrite(tercerLED, LOW);
  delay(1000);
}
