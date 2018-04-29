#define trigPin 12
#define echoPin 11
int buzzer = 13;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  delay(100);
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  Serial.print("Distance in CM:");
  Serial.println(dist);
  if (distance <= 10) // change the distance here
  {
    Serial.println (" Drain Blocked ");
    Serial.print (" Distance= ");
    Serial.println (distance);
    digitalWrite (buzzer, HIGH);
    delay (1000);
  }
  else {
    Serial.println (" Drain Clear ");
    Serial.print (" Distance= ");
    Serial.println (distance);
    digitalWrite (buzzer, LOW);
    delay (1000);
  }

}
delay(500);
}

