/*This code explains the working of tilt sensor with buzzer*/

#define Tilt A0 //analog output from tilt sensor module is connected to A0
#define BUZZER 13 //LED at D3 pin

void setup() {
  //setup the input or output pin
  pinMode(BUZZER, OUTPUT);
  pinMode(Tilt, INPUT);
  digitalWrite(BUZZER, LOW); //off LED
}

void loop() {
  if (analogRead(Tilt)) //if the AO from Tilt sensor is low, no tilt detected.
    //You might need to adjust the potentiometer to get reading
    digitalWrite(BUZZER, HIGH);
  else
    digitalWrite(BUZZER, LOW);
}
