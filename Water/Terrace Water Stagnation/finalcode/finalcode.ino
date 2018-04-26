#include<NewPing.h>

#define trigger 12//attach trigger to D7 of Arduino UNO
#define echo 11//attach echo pin to D8 of Arduino UNO

int r = 9;
int g = 8;
int b = 7;


#define max_distance 100//distance between sensors and opposite side is 100cm

NewPing sensor(trigger,echo,max_distance);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int dist=sensor.ping_cm();//find the distance
Serial.print("Distance:");
Serial.println(dist);
Serial.print(" cm");

if (dist <= 10){
  red();
}
else if (dist >= 11 && dist <= 20){
  orange();
}
else {
  green();
}
}

void blinkred() {
  digitalWrite(r, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
  delay(1000);                       // wait for a second
  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
  delay(1000);
}

void blinkblue() {
  off();                  // wait for a second
  digitalWrite(r, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(1000);
}

void blinkgreen() {
  off();                       // wait for a second
  digitalWrite(r, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);
  delay(1000);
}

void blinkpurple() {
  off();                         // wait for a second
  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(1000);
}
void blinkorange() {
  off();                        // wait for a second
  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);
  delay(1000);
}

void blinkyellow() {
  off();                      // wait for a second
  digitalWrite(r, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  delay(1000);
}

void blinkwhite() {
  off();                      // wait for a second
  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  delay(1000);
}

//nonblink
void red() {                      // wait for a second
  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
  delay(2000);
  off();
}

void blue() {                   // wait for a second
  digitalWrite(r, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(2000);
  off();
}

void green() {                    // wait for a second
  digitalWrite(r, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);
  delay(2000);
  off();
}

void purple() {                      // wait for a second
  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(2000);
  off();
}
void orange() {                      // wait for a second
  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);
  delay(2000);
  off();
}

void yellow() {                     // wait for a second
  digitalWrite(r, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  delay(2000);
  off();
}

void white() {               // wait for a second
  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  delay(2000);
  off();
}

void off() {
  digitalWrite(r, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
  delay(1000);
}

