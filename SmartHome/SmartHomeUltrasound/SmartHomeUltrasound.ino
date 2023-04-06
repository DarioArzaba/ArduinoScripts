
//Envia ultrasonido en una onda de 40,000Hz con HC-SR04
//Trig High for 10 us envia 8 Ciclos.
//Velocidad sonido = 340 m/s = 0.034 cm/us
//Echo recibe y muestra el tiempo que tardo en regresar.
//Tiempo = Distancia / Velocidad del Sonido
//Distancia = (Tiempo * Velocidad) / 2
//El tiempo se tiene que dividir entre dos por que tiene que ir y regresar.

const int trigPin = 9;
const int echoPin = 11;

long tiempo;
int distancia;
float velocidadSonido = 0.034;

void setup() {

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {

  //Asegurar que esta apagado.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Enviar señal de 8 ciclos en 10 us
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  //Apagar
  digitalWrite(trigPin, LOW);
  
  //Obtener tiempo que tarda en regresar.
  tiempo = pulseIn(echoPin, HIGH);
  //Calcular distancia recorrida en base al tiempo y a la velocidad.
  distancia= (tiempo*velocidadSonido)/2;
  if (distancia <= 500 && distancia >= 0){
    Serial.print("Distancia: "); Serial.print(distancia); Serial.print(" cm"); Serial.println();
    delay(200);
  }
 
}
