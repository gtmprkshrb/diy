int rainsense = A2; // analog sensor input pin 0


void setup() {
  Serial.begin(9600);

  pinMode(rainsense, INPUT);
}
void loop() {
  int rainSenseReading = analogRead(rainsense);
  Serial.println(rainSenseReading); // serial monitoring message
  delay(250);// rain sensing value from 0 to 1023.
  
}
