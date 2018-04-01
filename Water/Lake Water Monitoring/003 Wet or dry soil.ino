int sensor_pin = A0;
//int output_value ;
void setup()
{
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);

}

void loop()
{
  int value = analogRead(sensor_pin);
  //value = value / 10;
  Serial.println(value);
  if ( value < 400)
  {
    Serial.println("Wet soil");
    digitalWrite (7, HIGH);
    delay(1000);
  }
  else
  {
    Serial.println("Dry soil"); // Greater than 400
    digitalWrite (7, LOW);
    delay(1000);
  }
}



