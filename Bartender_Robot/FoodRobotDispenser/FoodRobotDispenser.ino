#include <IRremote.h>                           //Incluir libreria Infrarojo
#include <AFMotor.h>                            //Incluir libreria de Adafruit Motor Shield V.1
#include <Servo.h>                              //Incluir libreria de Servos

Servo myservo;                                  //Crear un nuevo servo
int servoPos = 0;                               //Valor del servo de 0 a 180
int RECV_PIN = 11;                              //Pin que recibe la señal del sensor IR
IRrecv irrecv(RECV_PIN);                        //Crea recibidor en el pin 11.
decode_results results;                         //Crea decodificador
int ledRojo = 7;                                //Pin del Led Rojo en el 7
int ledVerde = 5;                               //Pin del Led Verde en el 5
AF_DCMotor motor(3);                            //Motor DC en el shield en el puerto M3

void setup() {  
  Serial.begin(9600);                           //Inicia puerto serial
  Serial.println("Enabling IRin");              //Avisar al usuario
  irrecv.enableIRIn();                          //Inicia recibidor en pin 11
  Serial.println("Enabled IRin");               //Si es exitoso se imprime este mensaje
  myservo.attach(9);                            //Inicia el servo en el pin 9
  myservo.write(0);                             //Mueve el cervo a posicion de inicio
  pinMode(ledRojo, OUTPUT);                     //Establece pin 7 como pin de salida para LED
  motor.setSpeed(200);                          //Establece velocidad de 0 a 255 de motor DC
  motor.run(RELEASE);                           //Detiene el motor DC al inicio
  pinMode(ledVerde, OUTPUT);                    //Establece pin 5 como pin de salida para LED
  delay(1000);                                  //Delay para esperar que el sistema inicie
}

void loop() {
  if (irrecv.decode(&results)) {                //Si el recibidor acaba de decodificar al decodificador
    Serial.println(results.value);              //Entonces imprimir el valor decodificado
    if (results.value == 2704) {                //Si el valor decodificado es 2704
      myservo.write(180);                       //Entonces mover el servo 180 grados
      digitalWrite(ledRojo, LOW);               //Apagar el LED Rojo
      digitalWrite(ledVerde, HIGH);             //Prender el LED Verde
      motor.run(FORWARD);                       //Activar el motor DC
      delay(3000);                              //Esperar por 3 segundos
    } 
    myservo.write(0);                           //Despues de los tres segundos regresar Servo a 0
    digitalWrite(ledRojo, HIGH);                //Prender LED ROJO
    digitalWrite(ledVerde, LOW);                //Apagar LED VERDE
    delay(1000);                                //Esperar 1 segundo a que el servo regrese.
    motor.run(RELEASE);                         //Parar el motor DC
    irrecv.resume();                            //Reiniciar el valor del recibidor.
  }
  delay(100);                                   //Esperar 0.1 segundos para evitar que se prenda inmediatamente
}
