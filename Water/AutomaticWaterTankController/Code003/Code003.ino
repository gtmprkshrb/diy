/*This code explains automatic overhead tank controller with Distance sensor, Solenoid valve and buzzer too
 * Buzzer beeps and solenoid valve automatically closes if water reches maximum height of tank
 */

#define trigPin 12 //digital pin 12
#define echoPin 11 //digital pin 11
int solenoidpin = 3; //digital pin 3
int buzzer = 13; //digital pin 13

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(solenoidpin, INPUT);
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
    digitalWrite(solenoidpin, LOW);
    tone(buzzer, 1000, 500);
    delay(500);
  }
  else  {
    digitalWrite(buzzer, LOW);
    digitalWrite(solenoidpin, HIGH);

  }
  delay(500);
}

