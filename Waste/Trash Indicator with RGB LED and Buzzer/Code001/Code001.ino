/*This code exaplins the working of distance sensor that measures distance or height of object.
Test the sensor with soild objects like scale, notebook or your own hand
*/

#define trigPin 12 //Digital pin 12
#define echoPin 11 //Digital pin 11

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  if (dist >= 300 || dist <= 2) //CHANGE
  {
    Serial.print("\n Out Of Range");
  }
  else {

    Serial.println("\n Distance in CM: ");

    Serial.print( dist);

  }
  delay(1000);
}
