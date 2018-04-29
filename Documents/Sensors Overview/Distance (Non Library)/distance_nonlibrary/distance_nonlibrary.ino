/*
  Coded By: https://electronicsproject.org
*/

#define trigPin 12
#define echoPin 11

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  distance();
}

void distance() {
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  if (dist >= 300 || dist <= 0) {
    Serial.println("Out Of Range");
  }
  else {
    Serial.println("Distance in CM: ");
    Serial.print(dist);
  }
  delay(500);
}

