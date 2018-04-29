int sensorpin = A1; //Analog pin 1
const int MOISTURE_LEVEL = 700; // change value depending on moisture level in dry and wet soil

int solenoidpin = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorpin, OUTPUT);
  pinMode(solenoidpin, OUTPUT);
}

void loop()
{
  int moisture = analogRead(sensorpin);

  Serial.print("Moisture = ");
  Serial.println(moisture);

  if (moisture < MOISTURE_LEVEL)
  {
    digitalWrite(solenoidpin, HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(solenoidpin, LOW);
    delay(1000);
  }

  delay(500);
}
