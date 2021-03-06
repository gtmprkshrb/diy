#include <Adafruit_FONA.h>
#include <SoftwareSerial.h>

#define FONA_RX 5
#define FONA_TX 6
#define FONA_RST 4

SoftwareSerial fona (FONA_TX, FONA_RX);
Adafruit_FONA fona = Adafruit_FONA(FONA_RST);
char replybuffer[255];

void setup() {
  Serial.begin(9600);
  fona.begin(9600);
}

void loop() {
  fona.print("AT+CMGF=1\r");
  delay(1000);
  fona.print("AT+CMGS=\"+91xxxxxxxxxxx\"\r");// enter your phone number
  
  delay(1000);
  fona.print("Hi!!!");
  fona.print("\r");
 
  delay(1000);
  fona.println((char)26);
  fona.println();
 
  delay(10000);
}

