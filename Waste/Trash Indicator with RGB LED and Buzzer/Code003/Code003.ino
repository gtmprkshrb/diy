/*this code explains the working of trash can with RGB LED , buzzer and distance sensor
 * distance sensor measures height, if trash can is near full, Red light glows and buzzer beeps.
 * Here we use Red and Green light alone in RGB.
 * Uses Distance sensor, RGB LED , buzzer*/

#define trigPin 12
#define echoPin 11
int buzzer = 13;

int r = 7;
int g = 8;
int b = 9;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
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
  if (dist > 0 && dist < 26) //Change the distance range value here
  {
    tone(buzzer, 1000, 500);
    delay(500);
    blinkred();
  }
  else  {
    digitalWrite(buzzer, LOW);
    delay(500);
    blinkgreen();
  }
  delay(500);
}
void blinkred() {

  digitalWrite(r, HIGH);    // turn the LED ON
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  delay(1000);
}

void blinkgreen() {

  digitalWrite(r, LOW);    // turn the LED ON
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(1000);
}
