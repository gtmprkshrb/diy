#define Tilt 2 //Digital output from tilt sensor module is connected to D2
#define BUZZER 3 //LED at D3 pin

void setup() {
//setup the input or output pin
pinMode(BUZZER, OUTPUT);
pinMode(Tilt, INPUT);
digitalWrite(BUZZER, LOW); //off LED
}

void loop() {
if(digitalRead(Tilt)) //if the DO from Tilt sensor is low, no tilt detected.
//You might need to adjust the potentiometer to get reading
digitalWrite(BUZZER,HIGH);
else
digitalWrite(BUZZER,LOW);
}
