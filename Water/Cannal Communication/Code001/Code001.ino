/*this code explains the function of soil moisture sensor*/
int sensor_pin = A1;

void setup()
{
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

void loop()
{
  int value = analogRead(sensor_pin);
  Serial.println(value);
  if ( value < 400)
  {
    Serial.println("Wet soil");
    delay(2000);
  }
  else
  {
    Serial.println("Dry soil"); // Greater than 400
    delay(2000);
  }
}


