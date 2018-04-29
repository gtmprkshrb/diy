
#define trigPin 11
#define echoPin 12
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
    red();
  }
  else if (dist >= 11 && dist <= 20) {
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

