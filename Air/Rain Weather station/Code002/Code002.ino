int rainsense = A2; // analog sensor input pin 0
int buzzer = 13; // digital output pin 13 - buzzer output


void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(rainsense, INPUT);
}
void loop() {
  int rainSenseReading = analogRead(rainsense);
  Serial.println(rainSenseReading); // serial monitoring message
  delay(250);// rain sensing value from 0 to 1023.
  // from heavy rain - no rain.

  if (rainSenseReading < 350) {
    digitalWrite(buzzer, LOW);
    delay(200);
    
  }
  else if (rainSenseReading > 350 && rainSenseReading < 900) { // if not raining
    digitalWrite(buzzer, HIGH); // turn off buzzer
    delay(500);
    digitalWrite(buzzerout, LOW);
  }
  delay(1000);
}
