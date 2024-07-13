#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#define rxPin 16 
#define txPin 17 
SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);
}

void loop() {
  float t, h;
  if(mySerial.available()>0){
    String data = mySerial.readStringUntil('\n');
    StaticJsonDocument<100> doc;
    DeserializationError error = deserializeJson(doc, data);
    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return;
    }
    t = doc["t"];
    h = doc["h"];
    Serial.println("T="+String(t)+"\tH="+String(h));
  }
}
