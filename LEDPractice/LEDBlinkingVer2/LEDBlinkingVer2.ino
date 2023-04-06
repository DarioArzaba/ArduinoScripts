/*
Asignamos nombre al pin 13.
Configuramos al pin 13 en modo Output
Repetir:
  Generamos una corriente Alta.
  Esperamos 1 segundo.
  Generamos una corriente Baja.
  Esperamos 1 segundo.

 */

int pin_para_LED = 12;

void setup() {
  pinMode(pin_para_LED, OUTPUT);
}

void loop() {
  digitalWrite(pin_para_LED, HIGH);
  delay(1000);              
  digitalWrite(pin_para_LED, LOW);    
  delay(1000);              
}
