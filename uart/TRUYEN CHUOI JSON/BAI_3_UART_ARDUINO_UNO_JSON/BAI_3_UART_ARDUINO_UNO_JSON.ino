#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#define rxPin 8 
#define txPin 9 
SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);
}

void loop() {
  float t = random(30.0,38.0);
  float h = random(40, 90);
  StaticJsonDocument<100> doc;
  doc["t"] = t;
  doc["h"] = h;
  String Data;
  serializeJson(doc, Data);
  mySerial.println(Data);

  Serial.println(Data);
  delay(1000);
}
