
#include <IRremote.h>               //Libreria de Infra Rojo
int RECV_PIN = 11;                  //Señal del sensor IR al pin 11
IRrecv irrecv(RECV_PIN);            //Pin que recibe es el 11
decode_results results;             //Decodificador

void setup()  {
  Serial.begin(9600);               //Iniciar puerto serial
  irrecv.enableIRIn();              //Activar recibidor
}

void loop() {
  //Si el recibidor decodifica exitosamente al decodificador
  //Entonces imprimir el valor del decodificador en hexagesimal
  //Reiniciar el valor del decodificador para recibir siguiente valor.
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}
