void setup() {
  Serial.begin(115200);
  Serial.println("Hello PC!");
}

void loop() {
  if(Serial.available()>0){
    String data = Serial.readString();
    Serial.println("Data from ESP32: "+ data);
  }
}
