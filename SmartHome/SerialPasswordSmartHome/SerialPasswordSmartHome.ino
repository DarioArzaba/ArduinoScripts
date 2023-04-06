//Prende o Apaga LED Verde o Rojo, parpadeando si contraseña serial es correcta

int LEDROJO = 5;                                                    
int LEDVERDE = 9;                                             
String readStringTemp;
String secret = "dario"; 

void setup() {
 Serial.begin(9600);                      
 pinMode(LEDROJO, OUTPUT);             
 pinMode(LEDVERDE, OUTPUT);                                 
 Serial.println("Escribe la contraseña correcta: "); 
}

void loop() {

 while (Serial.available()) {  //Si hay algo en el serial (despues de presionar enter)
    delay(2);                  //Dejar que entre el siguiente byte de info      
    char c = Serial.read();    //Leer caracter del serial y borrarlo del buffer
    readStringTemp += c;      
    readStringTemp.trim();                                                
  }
  
if (readStringTemp.length() >0) {
    Serial.println(readStringTemp);
    if(secret == readStringTemp)  {
      Serial.println("Correcto");
      for (int i = 0; i < 3; i++) {
        digitalWrite(LEDVERDE, HIGH);
        delay(200);
        digitalWrite(LEDVERDE, LOW);
        delay(200);
      }
    } else {
      Serial.println("Incorrecto");
      for (int i = 0; i < 3; i++) {
        digitalWrite(LEDROJO, HIGH);
        delay(200);
        digitalWrite(LEDROJO, LOW);
        delay(200);
      }
      }
    readStringTemp="";
  }
  
}
