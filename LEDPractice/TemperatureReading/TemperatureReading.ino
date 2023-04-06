char command;
String string;
#define led 13
#define lm A1

  void setup()
  {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
  }

  void loop()
  {
    if (Serial.available() > 0) 
    {string = "";}
    
    while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
      if(command == ':')
      {
        break;
      }
      
      else
      {
        string += command;
      }
      
      delay(1);
    }
    
    if(string == "TO")
    {
      TempOn();
    }
    
    if(string =="TF")
    {
      TempOff();
    }
 }

    void TempOn()
    {  
          int x = analogRead(lm);
          float temp = (5.0*x*100.0)/1024.0;
          Serial.println(temp);
          digitalWrite(led, HIGH);
          delay(500);
    }
    
    void TempOff()
    {
      digitalWrite(led, LOW);
      delay(500);
    }
    
