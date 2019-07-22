#include <SPI.h>
#include <RF24.h>

RF24 radio(8,10);
const byte address[6] = "00001";

void setup() {
      Serial.begin(9600);

      radio.begin();
      Serial.println("checking if chip connected");
      bool check = radio.isChipConnected();
      Serial.print("check-");
      Serial.println(check);
  
      radio.openWritingPipe(address);
      radio.setPALevel(RF24_PA_HIGH);
      radio.stopListening();
}


void loop() {      
  const char msg[30] = "f";
  const char msg2[30] = "l";
  const char msg3[30] = "b";
  const char msg4[30] = "r";
  const char msg5[30] = "s";
  char t = 'q';
  if(Serial.available())
  {
    t=Serial.read();
    if(t == 'w')
    {
      radio.write(&msg,sizeof(msg));
      digitalWrite(13,1);
    }
    else if(t == 'a')
    {
      radio.write(&msg2,sizeof(msg2));
      digitalWrite(13,1);
    }
    else if(t == 's')
    {
      radio.write(&msg3,sizeof(msg3));
      digitalWrite(13,1);
    }
    else if(t == 'd')
    {
      radio.write(&msg4,sizeof(msg4));
      digitalWrite(13,1);
    }
    else if(t == 'q')
    {
      radio.write(&msg5,sizeof(msg5));
      digitalWrite(13,0);
    }
  }
  delay(10);
}
