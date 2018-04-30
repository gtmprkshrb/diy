/*This code explains the drain alert based on mositure level with
 * help of moisture sensor and alert user by beeping with buzzer
 */
int sensorpin = A0;
int buzzer = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(sensorpin, INPUT);
  pinMode(buzzer, OUTPUT);
}
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1000);

  if (sensorValue > 400) {
    Serial.println (" Low moisture ");
    digitalWrite (buzzer, HIGH);
    delay(1000);
  }
  else {
    digitalWrite (buzzer, LOW);
    delay(1000);
  }
}
