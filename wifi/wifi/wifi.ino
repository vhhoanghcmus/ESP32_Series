#include <Wifi.h>

const char* ssid = "VuHoang"; // SSID
const char* password = "19942003"; // PASSWORD
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("");
  Serial.print("Connecting to WIFI...");
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED){ //CHECK Connect
    delay(500);
    Serial.print(".");
  }
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.print("IP address: ");
    Serial.print(WiFi.localIP()));
}

void loop() {
  // put your main code here, to run repeatedly:

}
