// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  5  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int greenPin = 10;
int redPin = 9;
int bluePin = 11;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE


void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  delay(2000);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  if (sonar.ping_cm() < 20)
  { digitalWrite(redPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    delay(500);                       // wait for a second
  }

  else
  { digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    delay(500);
  }
}
