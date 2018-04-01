// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     8  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

#define RELAY 10;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(10, OUTPUT);
}

void loop() {
  delay(4000);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  if
  (sonar.ping_cm()>= 25)       // If Distance is greater than 50 cm then it should be on
  { digitalWrite(10, HIGH);   // In relay made by me LOW means ON
    delay(500);
  }

  else
  { digitalWrite(10, LOW);   // In relay made by me HIGH means OFF
  }
}
