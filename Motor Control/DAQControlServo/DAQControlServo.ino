#include "MCP_DAC.h" //libreria
MCP4821 myDAC;       //objeto dac
int val,kp=5,fs=10,ki=2,kd=15;
float planta,referencia,error0=0,error1=0,yi=0,y=0,y1=0,yd=0;
 
void setup(){
  myDAC.begin(10);     //inicializa objeto, CS en pin 10
  myDAC.analogWrite(0);
  Serial.begin(115200);
}
 
void loop(){
  referencia=(float)analogRead(0)*.00488;
  planta=(float)analogRead(1)*.00488;
  error0=referencia-planta;
  yd=2*fs*kd*(error0-error1);
  yi=(error0+error1)/2*fs;
  y=int(kp*error0+yd+kp*yi)*819.2;
  if(y>4096)
    y=4096;
  if(y<0)
    y=0;
  myDAC.analogWrite(y);  //salida de voltaje a 12 bits
  delay(fs);
  error1=error0;
  y1=y;
}