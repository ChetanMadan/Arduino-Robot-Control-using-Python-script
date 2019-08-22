#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8,10);
const byte address[6] = "00011";

void forward()
{
  digitalWrite(A0,1);
  digitalWrite(A1,0);

  digitalWrite(A2,1);
  digitalWrite(A3,0);

  digitalWrite(4,1);
  digitalWrite(5,0);

  digitalWrite(6,1);
  digitalWrite(7,0);
}

void stopm()
{
  digitalWrite(A0,0);
  digitalWrite(A1,0);

  digitalWrite(A2,0);
  digitalWrite(A3,0);

  digitalWrite(4,0);
  digitalWrite(5,0);

  digitalWrite(6,0);
  digitalWrite(7,0);
}

void reverse()
{
  digitalWrite(A0,0);
  digitalWrite(A1,1);

  digitalWrite(A2,0);
  digitalWrite(A3,1);

  digitalWrite(4,0);
  digitalWrite(5,1);

  digitalWrite(6,0);
  digitalWrite(7,1);
}

void left()
{
  digitalWrite(A0,1);
  digitalWrite(A1,0);

  digitalWrite(A2,0);
  digitalWrite(A3,1);

  digitalWrite(4,0);
  digitalWrite(5,1);

  digitalWrite(6,1);
  digitalWrite(7,0);
}

void right()
{
  digitalWrite(A0,0);
  digitalWrite(A1,1);

  digitalWrite(A2,1);
  digitalWrite(A3,0);

  digitalWrite(4,1);
  digitalWrite(5,0);

  digitalWrite(6,0);
  digitalWrite(7,1);
}

void setup() {
  Serial.begin(9600);

  radio.begin();
  Serial.println("checking if chip connected");
  bool check = radio.isChipConnected();
  Serial.print("check-");
  Serial.println(check);
  
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.startListening();
  
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);

  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  radio.startListening();
  if (radio.available()) {
    char message;
    radio.read(&message, sizeof(message));
    Serial.println(message);
    if (message == 'f')
    {
      forward();
    }
    else if (message == 'l')
    {
      left();
    }
    else if (message == 'r')
    {
      right();
    }
    else if (message == 'b')
    {
      reverse();
    }
    else if (message == 's')
    {
      stopm();
    }
  }
  delay(100);
}
