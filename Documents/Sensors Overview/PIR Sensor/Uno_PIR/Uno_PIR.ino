/*
   PIR sensor tester
   Read More here: https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor?view=all
   Thanks Adafruit!
*/

int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int count = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);  // read input value
  count = count + 1;
  Serial.println(count);
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");

      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH) {
      // we have just turned of
      Serial.println("Motion ended!");
      count = 0;
      Serial.println(count);
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}