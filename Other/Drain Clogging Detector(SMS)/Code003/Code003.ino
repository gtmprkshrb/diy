/*This code explains the working of Drain clog detector.
   Based on distance sensor, drain will be noted and SMS will be send to user or authorities to
   clear the drain
*/

#include <Adafruit_FONA.h>
#include <SoftwareSerial.h>

#define FONA_RX 5
#define FONA_TX 6
#define FONA_RST 4
SoftwareSerial fona (FONA_TX, FONA_RX);

Adafruit_FONA fona = Adafruit_FONA(FONA_RST);
char replybuffer[255];

#define trigPin 12
#define echoPin 11

void setup() {
  Serial.begin(9600);
  fona.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  delay(100);
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  Serial.print("Distance in CM:");
  Serial.println(dist);

  fona.print("AT+CMGF=1\r");
  delay(1000);            //for setting the network
  fona.print("AT+CMGS=\"+91xxxxxxxxx\"\r"); //Change your number

  if (distance <= 10) // change the distance here
  {
    Serial.println (" Drain Blocked ");
    Serial.print (" Distance= ");
    Serial.println (distance);
    fona.print("Drain Blocked");
    fona.print("\r");
    delay(10000);        //gap in sending messages//
    fona.println((char)26);
    fona.println();
    delay(10000);
  }
  delay(500);
}

