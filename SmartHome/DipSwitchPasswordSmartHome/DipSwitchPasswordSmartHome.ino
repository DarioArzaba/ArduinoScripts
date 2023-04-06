//LED y Buzzer prenden con DIP Switch contraseña, activado por evento de boton
//Potenciometroo controla LED

int potPin= A0; 
int LEDPin= 9;
int readValue;
int writeValue;
int buzzer = 11; 
int buttonPin = 10; 
int readButtonValue = 0;

int dip5 = 7;
int readDip5 = 0;
int dip6 = 6;
int readDip6 = 0;
int dip7 = 5;
int readDip7 = 0;
int dip8 = 4;
int readDip8 = 0;
int LED2Pin = 3;
unsigned long previousMillis1 = 0;  
long OnTime = 1000;        
boolean correctPassword = false;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(LED2Pin, OUTPUT);
  pinMode(dip5, INPUT);
  pinMode(dip6, INPUT);
  pinMode(dip7, INPUT);
  pinMode(dip8, INPUT);
  Serial.begin(9600);
}

void loop() {

    unsigned long currentMillis = millis();
  
    readValue = analogRead(potPin);
    writeValue = (255.0/1023.0) * (readValue);
    
    readButtonValue = digitalRead(buttonPin);
    if ((readButtonValue == HIGH) && (currentMillis - previousMillis1 >= OnTime)) {       

      previousMillis1 = currentMillis;

      readDip5 = digitalRead(dip5);
      readDip6 = digitalRead(dip6);
      readDip7 = digitalRead(dip7);
      readDip8 = digitalRead(dip8);
      Serial.print("Password = [ ");
      Serial.print(readDip5);
      Serial.print("  ");
      Serial.print(readDip6);
      Serial.print("  ");
      Serial.print(readDip7);
      Serial.print("  ");
      Serial.print(readDip8);
      Serial.print(" ]");
      Serial.println();

      correctPassword = (readDip5 == 0 && readDip6 == 0 && readDip7 == 0 && readDip8 == 0);
      
      if (correctPassword){
        digitalWrite(LED2Pin, HIGH);
      } else {
         digitalWrite(LED2Pin, LOW);
         tone(buzzer, 1000 , 200 );
      }
  } 

  analogWrite(LEDPin, writeValue);         //Modificar variable del led   

}

