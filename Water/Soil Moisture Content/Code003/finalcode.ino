int r = 7;
int g = 8;
int b = 9;
// initialize serial communication at 9600 bits per second:
void setup()
{ Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1000);

  if (sensorValue > 400) {
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
    delay(1000);
  }
  else {
    digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(g, HIGH);
    digitalWrite(b, LOW);
    delay(1000);
  }
}
