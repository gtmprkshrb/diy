/*This code explains the working of Parking sorter to park vehicles in gargage or parking areas
 * Uses RGB LED and distance sensor. Based on distance of vehicle, led color varies
 */

#define trigPin 12
#define echoPin 11
int r = 7;
int g = 8;
int b = 9;
int timetaken, dist;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {

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

  if (dist <= 10) {
    blinkred();
  }
  else if (dist >= 10 && dist <= 30) {
    blinkblue();
  }
  else {
    blinkgreen();
  }
}

void blinkred() {

  digitalWrite(r, HIGH);    // turn the LED ON 
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  delay(1000);
}

void blinkblue() {

  digitalWrite(r, LOW);    // turn the LED on
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(1000);
}

void blinkgreen() {

  digitalWrite(r, LOW);    // turn the LED ON
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(1000);
}

