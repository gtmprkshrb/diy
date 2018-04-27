/*If distance exceeds the tank height, buzzer beeps indicator user to switch of motor*/

#define trigPin 12
#define echoPin 11

int buzzer = 13;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(lcdpower, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  if (dist >= 300 || dist <= 0) {
    Serial.println("Out Of Range");
    digitalWrite(buzzer, HIGH);
  }
  else {
    Serial.println("Distance in CM: ");
    Serial.print(dist);
    digitalWrite(buzzer, LOW);
  }
  delay(500);



}
