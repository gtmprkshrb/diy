/*This code explains the working of Soil moisture sensor to find moisture level in soil
   Uses soil moisture sensor.
*/

int sensor_pin = A1;

void setup()
{
  pinMode(sensor_pin, INPUT);
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

void loop()
{
  int moisture  = analogRead(sensor_pin);
  Serial.println(moisture);
  delay(50);
}


