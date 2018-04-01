
// Example sketch for relay to work on if condition accoridng to DHT sensor
// Written by Maria Jose on 8th July, 2017
//

#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to
int relay = 7;

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)


// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  pinMode(relay, OUTPUT); // declaring relay as the output
  

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  float h = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %\t");


  if (h < 60) {
    digitalWrite(relay, LOW); // if temperature is greater than 30, relay (connected to fan) will switch on else will switch off
    
  }
  else {
    digitalWrite(relay, HIGH);
    

  }
}
