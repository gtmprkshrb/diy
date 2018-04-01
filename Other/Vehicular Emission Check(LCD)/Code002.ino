#include <Adafruit_FONA.h>
#include <SoftwareSerial.h>

#define FONA_RX 2
#define FONA_TX 3

//#define FONA_RST 4
SoftwareSerial fona (FONA_TX, FONA_RX);
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

