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
    {
      driver.send((uint8_t *)msg, strlen(msg));
      driver.waitPacketSent();
      digitalWrite(13,1);
    }
    else if(t == 'a')
    {
      driver.send((uint8_t *)msg2, strlen(msg2));
      driver.waitPacketSent();
      digitalWrite(13,1);
    }
    else if(t == 's')
    {
      driver.send((uint8_t *)msg3, strlen(msg3));
      driver.waitPacketSent();
      digitalWrite(13,1);
    }
    else if(t == 'd')
    {
      driver.send((uint8_t *)msg4, strlen(msg4));
      driver.waitPacketSent();
      digitalWrite(13,1);
    }
    else if(t == 'q')
    {
      driver.send((uint8_t *)msg5, strlen(msg5));
      driver.waitPacketSent();
      digitalWrite(13,0);
    }
  }
  delay(10);
}
