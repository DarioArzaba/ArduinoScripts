int ledPin = 12;                
int boton = 2;           
int botonEstado;                  
void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(boton, INPUT);   
}
void loop(){
  // Leer el estado del boton.
  // Si el boton no esta presionado realizar la secuencia.
  // Si el boton esta presionado 
  botonEstado = digitalRead(boton);   
  if (botonEstado == HIGH) {           
   digitalWrite(ledPin, HIGH);   
   delay(100);
   digitalWrite(ledPin, LOW);   
   delay(100);
 }
 
}
