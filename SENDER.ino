// SENDER
int buttonPins[] = {10,11,12,A0,A1,A2,A3,A4};
int buttonlen = sizeof(buttonPins) / sizeof(buttonPins[0]);
int rjPins[] = {2,3,4,5,6,7,8,9};
int rjLen = sizeof(rjPins) / sizeof(rjPins[0]);
int button = A0;
int onTime = 800;
void setup() {
  // put your setup code here, to run once:
pinMode(button,INPUT_PULLUP);
for (int i = 0; i<rjLen; i++) {
  pinMode(rjPins[i], OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rjPins[0], HIGH);


  if (!digitalRead(button)) {

    for (int i = 0; i<rjLen;i++) {
      digitalWrite(rjPins[i], HIGH);
      delay(onTime);
      digitalWrite(rjPins[i], LOW);
      
    }
  }
}
