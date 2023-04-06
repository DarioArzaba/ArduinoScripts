#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor Ventilador(1, MOTOR12_8KHZ);     //MotorDC 1 a 8KHZ de Frecuencia
Servo Puerta;                               //ServoMotor Puerta
int PuertaPos = 90;                         //ServoMotor inicia a 90
int PuertaVal = 0;                          //Puerta valor
int PuertaSignal = A3;                      //Senal para activar Puerta
int PuertaSignalVal = 0;
int VentiladorSignal = A0;                  //Senal para activar Ventilador
int VentiladorSignalVal = 0;

void setup() {

  Serial.begin(9600);
  Ventilador.setSpeed(200);                 //Velocidad Ventilador
  Puerta.attach(9);                         //PWM Digial 9 y 10
  pinMode(PuertaSignal, INPUT);             
  pinMode(VentiladorSignal, INPUT);
  Puerta.write(PuertaPos);
  
}

void loop() {

  PuertaSignalVal = digitalRead(PuertaSignal);
  VentiladorSignalVal = digitalRead(VentiladorSignal);
  if (PuertaSignalVal == HIGH){
    
  }

  Serial.print("Valor ");
Ventilador.run(FORWARD); // turn it on going forward
//delay(1000);
Serial.print("tock");
Ventilador.run(BACKWARD); // the other way
//delay(1000);
Serial.print("tack");
Ventilador.run(RELEASE); // stopped
//delay(1000);

PuertaVal = digitalRead(PuertaSignal);
if (PuertaVal == HIGH) {
  Puerta.write(180);
} else {
  Puerta.write(0);
}


  unsigned long TIEMPO_ACTUAL = millis();
  READ_DIMMER_POT = analogRead(DIMMER_POT);
  WRITE_DIMMER_POT = (255.0/1023.0) * (READ_DIMMER_POT);
  
  READ_BUTTON = digitalRead(BUTTON);

  TEMPERATURA = analogRead(SENSOR_TEMP);
  //10 MV por Grado Centigrado
  float MV = (TEMPERATURA/1024.0)*5000; 
  float CEL = MV/10;

  if ((CEL > MAX_TEMP) && (TIEMPO_ACTUAL - TIEMPO_ANTERIOR_VENTILADOR >= MIN_TIEMPO_VENTILADOR)) {
    TIEMPO_ANTERIOR_PUERTA = TIEMPO_ACTUAL;
    //PRENDER VENTILADOR
  }
  
  if ((READ_BUTTON == HIGH) && (TIEMPO_ACTUAL - TIEMPO_ANTERIOR_PUERTA >= MIN_TIEMPO_PUERTA)) {       

    TIEMPO_ANTERIOR_PUERTA = TIEMPO_ACTUAL;
   
    READ_DIP_ONE = digitalRead(DIPONE);
    READ_DIP_TWO = digitalRead(DIPTWO);
    READ_DIP_THREE = digitalRead(DIPTHREE);
    READ_DIP_FOUR = digitalRead(DIPFOUR);
    
    Serial.print("Password = [ "); Serial.print(READ_DIP_ONE); Serial.print("  "); Serial.print(READ_DIP_TWO); 
    Serial.print("  "); Serial.print(READ_DIP_THREE);  Serial.print("  "); Serial.print(READ_DIP_FOUR); Serial.print(" ]");
    Serial.println();
    CONTRA_CORRECTA = (READ_DIP_ONE == 0 && READ_DIP_TWO == 0 && READ_DIP_THREE == 0 && READ_DIP_FOUR == 0);
    
    if (CONTRA_CORRECTA){
      //ABRIR PUERTA
      for (int i = 0; i < 3; i++) {
        digitalWrite(LED_CORRECTO, HIGH);
        delay(200); //SIN DELAYS
        digitalWrite(LED_CORRECTO, LOW);
        delay(200); //SIN DELAYS
      }
      //ESPERAR
      //CERRAR PUERTA
    } else {
      for (int i = 0; i < 3; i++) {
        digitalWrite(LED_INCORRECTO, HIGH);
        delay(200); //SIN DELAYS
        digitalWrite(LED_INCORRECTO, LOW);
        delay(200); //SIN DELAYS
        tone(BUZZER, 1000 , 100 );
      }
    }
 } 

  analogWrite(LED_COCINA, WRITE_DIMMER_POT); 
  analogWrite(LED_BANO, WRITE_DIMMER_POT);
  analogWrite(LED_COMEDOR, WRITE_DIMMER_POT);
  analogWrite(LED_SALA, WRITE_DIMMER_POT);

}
