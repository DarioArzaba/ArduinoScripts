
int switchPin = 2; // Pin del boton 
int switchStatus;  // Estado del Switch
int buttonStatus;  // Estado del Boton
int buttonPresses = 0;   // Contador del Boton

void setup() {
  pinMode(switchPin, INPUT);    // Pin que leera el Boton
  Serial.begin(9600);           // Activa libreria Serial
  buttonStatus = digitalRead(switchPin);   // Leer el estado del boton.
}


void loop(){
  switchStatus = digitalRead(switchPin);  // Estado del switch es igual al boton.

  if (switchStatus != buttonStatus) {        
    if (switchStatus == LOW) {               
      buttonPresses++;               
      Serial.print("Button has been pressed ");
      Serial.print(buttonPresses);
      Serial.println(" times");
    }
  }
  buttonStatus = switchStatus;         
}
/* 
 *  
Boton = Apagado
Ciclo Inicial:
Switch: Apagado
Son diferentes? No
No hacer nada.

Ciclo (Se aprieta el boton):
Switch: Apretado
Son diferentes? Si
Switch es Apretado? Si
Cambiar contador.
Imprimir mensaje.
Boton = Apretado.

Boton = Apretado.
Ciclo (Se mantiene apretado):
Switch: Apretado.
Son diferentes? No.
No hacer nada.
Boton = Apretado.

Boton = Apretado.
Ciclo (Se suelta el boton):
Switch: Apagado.
Son diferentes? Si
Switch es Apretado? No
No hacer nada.
Boton = Apagado.

Boton = Apagado.
Ciclo Inicial.
Switch: Apagado.

*/

