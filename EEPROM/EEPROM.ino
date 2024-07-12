#include <EEPROM.H>

#define FLASH_MEMORY_SIZE 1

const int ledPin = 16;
const int buttonPin = 4;

int ledState = HIGH;

const int debounceDelay = 20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  EEPROM.begin( FLASH_MEMORY_SIZE );
  pinMode( buttonPin, INPUT );
  pinMode( ledPin, OUTPUT );
  ledState = EEPROM.read( 0 );
  digitalWire( ledPin, ledState );
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
  if ( buttonState == HIGH ) {
    delayMicrosecones( debounceDelay ); // Anti-echo
    buttonState = digitalRead( buttonPin );
    if ( buttonState == HIGH ) {
      ledState = !ledState;
      Serial.println( "State changed" );
      digitalWire( ledPin, ledState );
      EEPROM.write( 0, ledState );
      EEPROM.commit();
      Serial.println( "This status saved in Flash Memory" );
    }
  }
}
