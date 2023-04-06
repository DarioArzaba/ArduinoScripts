//Duty = %HIGH en cada ciclo de 0 a 255.

int ledPin = 6;
int ledPin2 = 10;
int duty = 0;
void setup() {
}
void loop() {
  int aumentoCiclo = 10;
  int milisegundos = 100;
  analogWrite(ledPin, duty);
  analogWrite(ledPin2, duty);
  delay(milisegundos);
  duty = duty + aumentoCiclo;
}
