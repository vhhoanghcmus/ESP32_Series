#include <SoftwareSerial.h>
#define rxPin 16
#define txPin 17
SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  Serial.begin(115200);

  mySerial.begin(115200);
}

void loop() {
  while (Serial.available()){ 
    char temp = char(Serial.read());
    Serial.print(temp);
    mySerial.write(temp);
  }

  while(mySerial.available()){
    Serial.write(mySerial.read());
  }  
}
