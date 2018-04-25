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
  if (dist > 0 && dist < 46) //CHANGE
  {

    tone(buzzer, 1000, 500);
    delay(500);
  }
  else  {
    digitalWrite(buzzer, LOW);
   

  }
  delay(500);
}

