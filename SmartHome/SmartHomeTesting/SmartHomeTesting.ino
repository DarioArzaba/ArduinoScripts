/*
PROGRAMA CASA INTELIGENTE
DARIO, NIRVANA Y ALAN

El programa se divide en 3 secciones:
1.- Dimmer: Potenciometro en A0 controla intensidad de LEDS en 9, 10, 11 y 6.
2.- Ventilador: Sensor de temperatura en A3 controla Motor DC por senal en A4 conectado a A0 del Shield
3.- Puerta: Boton en A1 checa valores del DIP Switch en 4, 7, 8 y 12.
  Si es incorrecto prende LED en 2 y suena buzzer en 5
  Si es correcto prende LED en 3 y controla Servomotor por senal en A5 conectado a A3 del Shield.

Errores: 
El foco en 6? se apaga al dar negativo en la puerta
El sensor de temperatura funciona pero no se prende el ventilador o se prende sin llegar a la temperatura
  Si esta enviando señal pero NO SE PRENDE EL LED :(
El servomotor ni siquiera se mueve:
  Necesito checar si se esta enviando la señal del servo con un LED!
  
*/


//DIMER

int LED_COCINA = 9;
int LED_BANO = 10;
int LED_COMEDOR = 11;
int LED_SALA = 6;
int DIMMER_POT = A0;
int READ_DIMMER_POT = 0;
int WRITE_DIMMER_POT = 0;

//VENTILADOR

int SENSOR_TEMP = A3;
int MAX_TEMP = 30;
int TEMPERATURA = 0;
int SENALVENTILADOR = A4;
float MILLIVOLTS;
float GRADOSCENTIGRADOS;

//PUERTA

int DIP_ONE = 4;
int DIP_TWO = 7;
int DIP_THREE = 8;
int DIP_FOUR = 12;
int READ_DIP_ONE = 0;
int READ_DIP_TWO = 0;
int READ_DIP_THREE = 0;
int READ_DIP_FOUR = 0;
int LED_INCORRECTO = 2; 
int LED_CORRECTO = 3;
int BUZZER = 5;
int BUTTON = A1;
int READ_BUTTON = 0;

int SENALPUERTA = A5;

unsigned long TIEMPO_ANTERIOR_PUERTA = 0;  
long MIN_TIEMPO_PUERTA = 2000;
boolean VENTILADOR = false;
boolean PUERTA = false;
boolean CONTRA_CORRECTA = false;

void setup() {

  Serial.begin(9600);

  //DIMER
  pinMode(LED_COCINA, OUTPUT);
  pinMode(LED_BANO, OUTPUT);
  pinMode(LED_COMEDOR, OUTPUT);
  pinMode(LED_SALA, OUTPUT);
  pinMode(DIMMER_POT, INPUT);

  //VENTILADOR
  pinMode(SENSOR_TEMP, INPUT);
  pinMode(SENALVENTILADOR, OUTPUT);
  digitalWrite(SENALVENTILADOR, LOW);
  
  //PUERTA
  pinMode(DIP_ONE, INPUT);
  pinMode(DIP_TWO, INPUT);
  pinMode(DIP_THREE, INPUT);
  pinMode(DIP_FOUR, INPUT);
  pinMode(LED_INCORRECTO, OUTPUT);
  pinMode(LED_CORRECTO, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(SENALPUERTA, OUTPUT);
  
}

void loop() {

  //OBTENER EL TIEMPO ACTUAL
  unsigned long TIEMPO_ACTUAL = millis();

  //OBTENER VALOR POTENCIOMETRO Y AJUSTAR PWM DE 0 a 255
  //PRENDER TODOS LOS LEDS DE ACUERDO AL VALOR DEL POTENCIOMETRO
  
  READ_DIMMER_POT = analogRead(DIMMER_POT);
  WRITE_DIMMER_POT = (255.0/1023.0) * (READ_DIMMER_POT);
  analogWrite(LED_COCINA, WRITE_DIMMER_POT); 
  analogWrite(LED_BANO, WRITE_DIMMER_POT);
  analogWrite(LED_COMEDOR, WRITE_DIMMER_POT);
  analogWrite(LED_SALA, WRITE_DIMMER_POT);

  //OBTENER TEMPERATURA Y AJUSTAR A GRADOS CENTIGRADOS

  TEMPERATURA = analogRead(SENSOR_TEMP);
  MILLIVOLTS = (TEMPERATURA/1024.0)*5000; 
  GRADOSCENTIGRADOS = MILLIVOLTS/10;
  if (GRADOSCENTIGRADOS > MAX_TEMP) {
    digitalWrite(SENALVENTILADOR, HIGH);
    VENTILADOR = true;
  } else {
    digitalWrite(SENALVENTILADOR, LOW);
    VENTILADOR = false;
  }

  //OBTENER VALOR DEL BOTON
  READ_BUTTON = digitalRead(BUTTON);
  
  //BOTON VALIDO DESPUES DE DOS SEGUNDOS.
  if ((READ_BUTTON == LOW) && ((TIEMPO_ACTUAL - TIEMPO_ANTERIOR_PUERTA) >= MIN_TIEMPO_PUERTA)) {
    TIEMPO_ANTERIOR_PUERTA = TIEMPO_ACTUAL;
   
    READ_DIP_ONE = digitalRead(DIP_ONE);
    READ_DIP_TWO = digitalRead(DIP_TWO);
    READ_DIP_THREE = digitalRead(DIP_THREE);
    READ_DIP_FOUR = digitalRead(DIP_FOUR);
    
    CONTRA_CORRECTA = (READ_DIP_ONE == 1 && READ_DIP_TWO == 1 && READ_DIP_THREE == 1 && READ_DIP_FOUR == 1);
    
    if (CONTRA_CORRECTA){
    
      digitalWrite(SENALPUERTA, HIGH);
      PUERTA = true;
      
      digitalWrite(LED_CORRECTO, HIGH);
      delay(200);
      digitalWrite(LED_CORRECTO, LOW);
      delay(200);
      digitalWrite(LED_CORRECTO, HIGH);
      delay(200);
      digitalWrite(LED_CORRECTO, LOW);
      delay(200);
      digitalWrite(LED_CORRECTO, HIGH);
      delay(200);
      digitalWrite(LED_CORRECTO, LOW);
      delay(200);
        
      digitalWrite(SENALPUERTA, LOW);
      PUERTA = false;
    
    } else {
      
      digitalWrite(LED_INCORRECTO, HIGH);
      delay(1000);
      digitalWrite(LED_INCORRECTO, LOW);
      delay(200);
      tone(BUZZER, 1000 , 100 );
      delay(100);
      
    }

    Serial.print("Password = [ "); Serial.print(READ_DIP_ONE); Serial.print("  "); Serial.print(READ_DIP_TWO); 
    Serial.print("  "); Serial.print(READ_DIP_THREE);  Serial.print("  "); Serial.print(READ_DIP_FOUR); Serial.print(" ]");
    Serial.print("   Temp =  "); Serial.print(GRADOSCENTIGRADOS); Serial.print("   VENT =  "); Serial.print(VENTILADOR); 
    Serial.print("   PUERTA =  "); Serial.print(PUERTA); 
    Serial.println();
    
  }
    
    
}
