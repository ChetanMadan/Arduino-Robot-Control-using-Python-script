#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup()
{
  Serial.begin(9600);	  // Debugging only
  if (!driver.init())
    Serial.println("init failed");
  pinMode(13,OUTPUT);    
}

void loop()
{
  const char *msg = "forward";
  const char *msg2 = "left";
  const char *msg3 = "reverse";
  const char *msg4 = "right";
  const char *msg5 = "stop";
  char t = 'q';
  if(Serial.available())
  {
    t=Serial.read();
    if(t == 'w')
    digitalWrite(13,1);
    else if(t == 'a')
    digitalWrite(13,1);
    else if(t == 's')
    digitalWrite(13,1);
    else if(t == 'd')
    digitalWrite(13,1);
    else if(t == 'q')
    digitalWrite(13,0);
  }
  delay(10);
}
