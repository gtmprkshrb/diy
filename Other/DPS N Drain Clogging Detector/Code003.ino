// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

#include <Adafruit_FONA.h>
#include <SoftwareSerial.h>

#define FONA_RX 2
#define FONA_TX 3

//#define FONA_RST 4
SoftwareSerial fona (FONA_TX, FONA_RX);
char replybuffer[255];

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

  Serial.begin(9600);
  fona.begin(9600);
}

void loop() {
  delay(5000);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  fona.print("AT+CMGF=1\r");
  delay(1000);            //for setting the network //
  fona.print("AT+CMGS=\"+919916192657\"\r");

  if (sonar.ping_cm() > 50)

  { fona.print("Saisbudtini");
    fona.print("\r");
  }

  delay(10000);        //gap in sending messages//
  fona.println((char)26);
  fona.println();

  delay(10000);
}
