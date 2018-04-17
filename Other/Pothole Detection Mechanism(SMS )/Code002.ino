#include <Adafruit_FONA.h>
#include <SoftwareSerial.h>

#define FONA_RX 9
#define FONA_TX 10

//#define FONA_RST 4
SoftwareSerial fona (FONA_TX, FONA_RX);
char replybuffer[255];
#define trigPin 6
#define echoPin 7

void setup() {

  fona.begin(9600);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  delay(500);
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  if (dist  <= 17) {
    Serial.print(dist);
    fona.print("AT+CMGF=1\r");
    delay(1000);
    fona.print("AT+CMGS=\"+91xxxxxxxxxx\"\r"); //enter your phone number

    delay(1000);
    fona.print("Pothole Detected!!!");
    fona.print("\r");

    delay(1000);
    fona.println((char)26);
    fona.println();

    delay(10000);

  }

}




