int ledRojo1 = 2;
int ledAmarillo1 = 3;
int ledVerde1 = 4;

int ledVerde3 = 5;
int ledAmarillo3 = 6;
int ledRojo3 = 7;
int ledCruce3 = 11;

int ledRojo2 = 8;
int ledAmarillo2 = 9;
int ledVerde2 = 10;


void setup() {
  
pinMode(ledRojo1,OUTPUT);
pinMode(ledAmarillo1,OUTPUT);
pinMode(ledVerde1,OUTPUT);

pinMode(ledRojo2,OUTPUT);
pinMode(ledAmarillo2,OUTPUT);
pinMode(ledVerde2,OUTPUT);

pinMode(ledVerde3,OUTPUT);
pinMode(ledAmarillo3,OUTPUT);
pinMode(ledRojo3,OUTPUT);
pinMode(ledCruce3,OUTPUT);

}

void loop() {

/*  */


digitalWrite(ledVerde3,HIGH);
digitalWrite(ledRojo1,HIGH);
digitalWrite(ledRojo2,HIGH);
delay(2000);

digitalWrite(ledVerde3,LOW);
digitalWrite(ledAmarillo3,HIGH);
delay(2000);

digitalWrite(ledAmarillo3,LOW);
digitalWrite(ledRojo3,HIGH);
digitalWrite(ledCruce3,HIGH);

delay(2000);

digitalWrite(ledCruce3,LOW);
digitalWrite(ledRojo1,LOW);
digitalWrite(ledVerde1,HIGH);
delay(2000);

digitalWrite(ledVerde1,LOW);
digitalWrite(ledAmarillo1,HIGH);
delay(2000);

digitalWrite(ledAmarillo1,LOW);
digitalWrite(ledRojo1,HIGH);
digitalWrite(ledRojo2,LOW);
digitalWrite(ledVerde2,HIGH);
delay(1000);

digitalWrite(ledVerde2,LOW);
digitalWrite(ledAmarillo2,HIGH);
delay(2000);

digitalWrite(ledAmarillo2,LOW);
digitalWrite(ledRojo2,HIGH);
digitalWrite(ledRojo3,LOW);
delay(2000);
}
