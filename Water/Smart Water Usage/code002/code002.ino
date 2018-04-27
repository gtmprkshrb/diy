/*This code exaplins the working of RGB LED.
   RGB LED comes in two types. Check the connection before testing.
  Connect the second leg pin of RGB LED either to Ground or 5v depending on their type.*/

int r = 7; // digital pin 7
int b = 8; // digital pin 8
int g = 9; // digital pin 9

void setup() {
  // put your setup code here, to run once:
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(r, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  red();
  delay(1000);
  green();
  delay(1000);
  blue();
  delay(1000);
}

void red() {
  digitalWrite(r, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
}

void green() {
  digitalWrite(g, LOW);
  digitalWrite(r, HIGH);
  digitalWrite(b, HIGH);
}

void blue() {
  digitalWrite(b, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(r, HIGH);
}

