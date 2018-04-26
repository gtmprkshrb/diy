int r = 9;
int g = 8;
int b = 7;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
//  blinkred();
//  blinkblue();
//  blinkgreen();
//  blinkyellow();
//  blinkpurple();
//  blinkorange();
//  blinkwhite();// wait for a second
//  red();
//  blue();
//  green();
  yellow();
  purple();
  orange();
  white();

off();

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

