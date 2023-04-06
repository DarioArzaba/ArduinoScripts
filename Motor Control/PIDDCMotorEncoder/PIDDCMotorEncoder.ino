int referencia = 511; // Valor deseado
// byte pinEncoder = A2; (Utilizar en vez de la referencia)
// int valorActualEncoder = 0; (Utilizar junto con el pin del Encoder)
byte pinPotenciometro = A3; // Señal de entrada del potenciometro 0 a 1023 mapeados a un voltaje de 0 a 5 V
int pinControlPWM = 3; // Señal de salida PWM para el control de velocidad mediante enable
int pinDireccionMotor1 = 5; // Señal de salida de direccion del motor 1
int pinDireccionMotor2 = 6; // Señal de salida direccion del motor 2
int valorActualPotenciometro = 0; // Valor del potenciometro temporal para realizar calculos.
int PWM = 0; // Valor que se enviara al pin de control PWM (3)
int error = 0; // Valor de la señal de error del sistema de control.
float control = 0.1; // Valor de la señal de control del sistema de control

float KP = 0.2; // Constante proporcional para el sistema de control P.
float KD = 2.0; // Constante derivativo para el sistema de control PD.
float KI = 0.0; // Constante integral para el sistema de control PID.
int valorSaturacionMinima = 50; // Constante para saturar el sistema.
int valorSaturacionMaxima = 255; // Constante para saturar el sistema.

float Theta, Theta_d;
int val_prev =0;
float e, e_prev = 0, inte, inte_prev = 0;
float Vmax = 12;
float Vmin = -12;
float V = 0.1; //IGUAL A CONTROL
const byte PWMPin = 6;
const byte DirPin1 = 7;
const byte DirPin2 = 8;

int unidadTiempo;
unsigned long tiempoActual;
unsigned long tiempoPasado = 0;
unsigned long errorPasado = 0;
const unsigned long eventInterval = 1500;
unsigned long previousTime = 0;
bool satMinAct = false;
bool satMaxAct = false;

void setup() {
  pinMode(pinControlPWM, OUTPUT);
  pinMode(pinDireccionMotor1,OUTPUT);
  pinMode(pinDireccionMotor2, OUTPUT);
  Serial.begin (9600);
}

void loop() {

  valorActualPotenciometro = analogRead(pinPotenciometro); // Pot con valor entre 0 y 1023
  // valorActualEncoder = analogRead(pinEncoder);
  tiempoActual = millis(); 
  unidadTiempo = (tiempoActual - tiempoPasado);
  error = referencia - valorActualPotenciometro; // Luego cambiar la referencia por valorActualEncoder
  // integracionError = integracionPasada + (unidadTiempo * (error + errorPasado) / 2);
  // control = KP * error + KI * integracionError + (KD * (error - errorPasado) / unidadTiempo);
  control = (KP * error) + (KD * (error - errorPasado) / unidadTiempo);
  
  // Si el error es mayor o igual a 1 (0 a 512) entonces PWM es el valor del pot 0 a 1023 * el control 0 a 51.2 
  // Saturar señal en el intervalo y finalmente establecer direccion.
  
  if (control > 5) {
      control = 5;
      // integracionError = integracionPasada;
    }
  if (control < 1) {
    control = 1;
    // integracionError = integracionPasada;
    // valorPasadoPotenciometro = valorActualPotenciometro;
  }

  if (error >=1) {
    PWM = valorActualPotenciometro*control;
    //PWM = map(valorActualPotenciometro, 511, 1023, 0 , 255);
    satMinAct = false;
    satMaxAct = false;
    if (PWM < valorSaturacionMinima) {PWM = valorSaturacionMinima; satMinAct = true;}
    if (PWM >= valorSaturacionMaxima) {PWM = valorSaturacionMaxima; satMaxAct = true;}
    digitalWrite(pinDireccionMotor1, HIGH);
    digitalWrite(pinDireccionMotor2, LOW);
  }

  // Si el error es menor a 0 (-1 a -511) entonces PWM es 255
  // Saturar señal en el intervalo y finalmente establecer direccion.
  if (error < 0) {
    PWM = 255;
    //PWM = map(valorActualPotenciometro, 511, 0, 0 , 255);
    satMinAct = false;
    satMaxAct = false;
    if (PWM < 50) { PWM = 50; satMinAct = true;}
    if (PWM >= 255) { PWM = 255; satMaxAct = true;}
    digitalWrite(pinDireccionMotor1, LOW);
    digitalWrite(pinDireccionMotor2, HIGH);    
  }

  analogWrite(pinControlPWM, PWM); // Señal de salida

  unsigned long currentTime = millis();
  if (currentTime - previousTime >= eventInterval) {
      Serial.println();
      Serial.print("-------------"); Serial.println();
      Serial.print("Pot Feedback: "); Serial.print(valorActualPotenciometro); Serial.println();
      Serial.print("Error: "); Serial.print(error); Serial.println();
      Serial.print("Control: "); Serial.print(control); Serial.println();
      Serial.print("PWM: "); Serial.print(PWM); Serial.println();
      Serial.print("Sat Min: ");  Serial.print(satMinAct); Serial.println();
      Serial.print("Sat Max: "); Serial.print(satMaxAct); Serial.println();
      Serial.print("Direccion: "); Serial.print(digitalRead(pinDireccionMotor1)); Serial.print(" , "); Serial.print(digitalRead(pinDireccionMotor2)); Serial.println();
      Serial.print("-------------");
      previousTime = currentTime;
  }
}