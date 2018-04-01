int sensor_pin = A0;

void setup()
{

  Serial.begin(9600);
  
  Serial.println("Reading From the Sensor ...");
  delay(2000);

}

void loop()
{
  int value = analogRead(sensor_pin);
  //value = value / 10;
  Serial.println(value);
  delay(1000);
}



