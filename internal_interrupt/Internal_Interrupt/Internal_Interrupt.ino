#define button 0
int numPress = 0;
void IRAM_ATT isr() {
  numPress += 1;
  isPress = true;
}
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(button, INPUT, INPUT_PULL);
  attachInterrupt(button, isr, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(isPress) {
    Serial.printf("Nut nhan da duoc an %u lan\n", numPress);
    isPress = false;

  }
}
