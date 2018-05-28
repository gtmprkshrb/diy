/*This code explains the working of smart toilet with distance sensor and servo motor, which
 * is fitted near the handle of  the flush tank.
 */
#include <Servo.h>

int servoPin = 10; //digital pin 10

Servo Servo1;

#define trigPin 11
#define echoPin 12

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Servo1.attach(servoPin);
}

void loop() {
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  if (dist > 20) {
    Servo1.write(0);
    delay(1000); // wait for a second
  }

  else
  {
    Servo1.write(90);
  }

  delay(500);

}

