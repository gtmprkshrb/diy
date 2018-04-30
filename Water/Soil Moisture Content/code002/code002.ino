/*
  This code exaplins the working of RGB LED.
  The long leg pin connected to Gnd.
  Common Ground version
*/

int r = 7;
int g = 8;
int b = 9;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  blinkred();
  blinkblue();
  blinkgreen();

}

void blinkred() {

  digitalWrite(r, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  delay(1000);
}

void blinkblue() {

  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(1000);
}

void blinkgreen() {

  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(1000);
}



