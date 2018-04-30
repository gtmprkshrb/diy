/*This code explains the working of moisture sensor*/

int sensorpin = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(sensorpin, INPUT);

}
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1000);
}
