#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(9600);	// Debugging only
    if (!driver.init())
         Serial.println("init failed");
    pinMode(13,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
}

void forward()
{
  digitalWrite(2,1); //right
  digitalWrite(3,0);
  digitalWrite(4,0); //left
  digitalWrite(5,1);
}
void right()
{
  digitalWrite(2,0); //right
  digitalWrite(3,1);
  digitalWrite(4,0); //left
  digitalWrite(5,1);
}
void left()
{
  digitalWrite(2,1); //right
  digitalWrite(3,0);
  digitalWrite(4,1); //left
  digitalWrite(5,0);
}
void back()
{
  digitalWrite(2,0); //right
  digitalWrite(3,1);
  digitalWrite(4,1); //left
  digitalWrite(5,0);
}
void stopm()
{
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
}
void loop()
{
    uint8_t buf[12]={};
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.println(char(buf[0]));
      if(char(buf[0]) == 'f') //forward function
      {
        forward();
        digitalWrite(13,1);
      }

      else if(char(buf[0]) == 'l') //left function
      {
        left();
        digitalWrite(13,1);
      }

      if(char(buf[0]) == 'r') //right function
      {
        right();
        digitalWrite(13,1);
      }

      if(char(buf[0]) == 'b') //back function
      {
        back();
        digitalWrite(13,1);
      }
      
      else if(char(buf[0]) == 's') //stop function
      {
        stopm();
        digitalWrite(13,0);
      }
    }
}
