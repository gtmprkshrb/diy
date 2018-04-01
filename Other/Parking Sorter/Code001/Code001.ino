
#define trigPin 7
#define echoPin 8

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
  if (dist >= 300 || dist <= 0) {
    Serial.print("Out Of Range");
  }
  else {

    Serial.println("\n Distance in CM: ");

    Serial.print( dist);

  }
  delay(500);
}
