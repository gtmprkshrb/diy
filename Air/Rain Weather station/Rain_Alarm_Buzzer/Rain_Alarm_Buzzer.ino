int rainsense = A2; // analog sensor input pin 0
int buzzerout = 8; // digital output pin 10 - buzzer output
int countval = 0; // counter value starting from 0 and goes up by 1 every second

void setup() {
  Serial.begin(9600);
  pinMode(buzzerout, OUTPUT);
  pinMode(rainsense, INPUT);
}
void loop() {
  int rainSenseReading = analogRead(rainsense);
  Serial.println(rainSenseReading); // serial monitoring message
  delay(250);// rain sensing value from 0 to 1023.
  // from heavy rain - no rain.

  if (rainSenseReading < 350) {
    digitalWrite(buzzerout, LOW);
    delay(200);
    //countval++; // increment count value
  }
  else if (rainSenseReading > 350 && rainSenseReading < 900) { // if not raining
    digitalWrite(buzzerout, HIGH); // turn off buzzer
    delay(500);
    digitalWrite(buzzerout, LOW);
  }
  delay(1000);
}
