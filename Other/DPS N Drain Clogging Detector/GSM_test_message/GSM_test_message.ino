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
  delay(1000);            //for setting the network //
  fona.print("AT+CMGS=\"+919916192657\"\r");
  
  delay(1000);                  
  fona.print("Saisbudtini");   
  fona.print("\r");

  delay(20000);        //gap in sending messages//
  fona.println((char)26);
  fona.println();
 
  delay(10000);
}

