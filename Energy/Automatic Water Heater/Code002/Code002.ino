// This code explains the working of One channel Relay
// Turns Relay ON and OFF for one second.
#define RELAY1  3                       


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin RELAY1 as an output.
  pinMode(RELAY1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RELAY1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(RELAY1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
