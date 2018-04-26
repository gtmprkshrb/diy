/*This code explains the working of Soil moisture sensor to find moisture level in soil
   Uses soil moisture sensor.
*/

int sensor_pin = A1;
int buzzer =13;
void setup()
{
  pinMode(buzzer, OUTPUT);
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
  if (moisture >0 && moisture < 400)  //Change the moisture range value here
  {
    tone(buzzer, 1000, 500);
    delay(500);
  }
  else if (moisture > 401 && moisture < 1023 {
    digitalWrite(buzzer, LOW);
  }
  delay(500);
}
}


