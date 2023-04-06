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
  digitalWrite(tercerLED, LOW);
  delay(100);

  digitalWrite(primerLED, LOW);
  digitalWrite(segundoLED, HIGH);
  digitalWrite(tercerLED, LOW);
  delay(100);

  digitalWrite(primerLED, HIGH);
  digitalWrite(segundoLED, LOW);
  digitalWrite(tercerLED, LOW);
  delay(100);

  digitalWrite(primerLED, LOW);
  digitalWrite(segundoLED, HIGH);
  digitalWrite(tercerLED, LOW);
  delay(200);

    digitalWrite(primerLED, HIGH);
  digitalWrite(segundoLED, LOW);
  digitalWrite(tercerLED, LOW);
  delay(200);

  digitalWrite(primerLED, LOW);
  digitalWrite(segundoLED, LOW);
  digitalWrite(tercerLED, HIGH);
  delay(300);

  digitalWrite(primerLED, LOW);
  digitalWrite(segundoLED, HIGH);
  digitalWrite(tercerLED, LOW);
  delay(200);

  digitalWrite(primerLED, HIGH);
  digitalWrite(segundoLED, LOW);
  digitalWrite(tercerLED, LOW);
  delay(500);

  digitalWrite(primerLED, LOW);
  digitalWrite(segundoLED, HIGH);
  digitalWrite(tercerLED, LOW);
  delay(200);

  digitalWrite(primerLED, LOW);
  digitalWrite(segundoLED, LOW);
  digitalWrite(tercerLED, HIGH);
  delay(50);

    digitalWrite(primerLED, LOW);
  digitalWrite(segundoLED, LOW);
  digitalWrite(tercerLED, LOW);
  delay(30);
  

    digitalWrite(primerLED, LOW);
  digitalWrite(segundoLED, LOW);
  digitalWrite(tercerLED, HIGH);
  delay(20);

  digitalWrite(primerLED, LOW);
  digitalWrite(segundoLED, LOW);
  digitalWrite(tercerLED, LOW);
  delay(30);
  
}
