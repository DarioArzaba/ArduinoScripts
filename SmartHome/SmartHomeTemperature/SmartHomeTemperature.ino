int valor;
int tempPin = A1;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  
  valor = analogRead(tempPin);
  //10 milovolts de mas por grados centigrados
  float mv = (valor/1024.0)*5000; 
  float cel = mv/10;
    
  Serial.print("Temperatura = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  

  digitalWrite(2, HIGH);
  

}
