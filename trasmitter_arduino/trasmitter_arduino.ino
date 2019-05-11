#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup()
{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  if(Serial.available()>0)
  {
    if(serial.read == 'w')
    {
      const char *msg1 = "forward";
      driver.send((uint8_t *)msg1, strlen(msg1));
      driver.waitPacketSent();
    }
    if(Serial.read == 'y')
    {
      const char *msg2 = "stop";
      driver.send((uint8_t *)msg2, strlen(msg2));
      driver.waitPacketSent();
    }


    if(serial.read == 'a')
    {
      const char *msg3 = "left";
      driver.send((uint8_t *)msg3, strlen(msg3));
      driver.waitPacketSent();
    }
    if(Serial.read == 'g')
    {
      const char *msg2 = "stop";
      driver.send((uint8_t *)msg2, strlen(msg2));
      driver.waitPacketSent();
    }


    if(serial.read == 's')
    {
      const char *msg4 = "Reverse";
      driver.send((uint8_t *)msg4, strlen(msg4));
      driver.waitPacketSent();
    }
    if(Serial.read == 'h')
    {
      const char *msg2 = "stop";
      driver.send((uint8_t *)msg2, strlen(msg2));
      driver.waitPacketSent();
    }


    if(serial.read == 'd')
    {
      const char *msg5 = "right";
      driver.send((uint8_t *)msg5, strlen(msg5));
      driver.waitPacketSent();
    }
    if(Serial.read == 'j')
    {
      const char *msg2 = "stop";
      driver.send((uint8_t *)msg2, strlen(msg2));
      driver.waitPacketSent();
    }
  }
}
