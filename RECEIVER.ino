// RECEIVER
int leds[] = { A0, A1, A2, A3, A4, A5, 10, 11 };
int ledSize = sizeof(leds) / sizeof(leds[0]);
int rjPins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int rjLen = sizeof(rjPins) / sizeof(rjPins[0]);

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < ledSize; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  DDRD = B00000000;
  DDRB &= ~(B00000011);
}
void loop() {
    uint8_t portDValue = PIND; // Read PORTD (pins 2-7)
    uint8_t portBValue = PINB; // Read PORTB (pins 8-9)
    for (int i = 2; i <= 7; i++) {
    if (portDValue & (1 << i)) { // Check if pin i is HIGH
      digitalWrite(leds[i-2], HIGH);
    } else {
            digitalWrite(leds[i-2], LOW);

    }
  }
    // Check pins 8 and 9
 
  
    for (int i = 0; i <= 1; i++) {
    if (portBValue & (1 << i)) { // Check if pin i is HIGH
      digitalWrite(leds[i+6], HIGH);
    } else {
      digitalWrite(leds[i+6], LOW);
    }
  delay(100); // Short delay for stability
}
}
