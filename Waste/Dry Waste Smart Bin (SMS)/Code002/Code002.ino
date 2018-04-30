/*This code explains easy waste segregation with help of distance sensor and
 * GSM 800 Module where user receives SMS if bin is full.
 * Use Vodafone SIM card
 */
#include <Adafruit_FONA.h>
#include <SoftwareSerial.h>

#define FONA_RX 5
#define FONA_TX 6
#define FONA_RST 4
SoftwareSerial fona (FONA_TX, FONA_RX);

Adafruit_FONA fona = Adafruit_FONA(FONA_RST);
char replybuffer[255];


int timetaken, dist;

#define trigPin 12  // Arduino pin 12 connected to trigger pin on the ultrasonic sensor.
#define echoPin 11  // Arduino pin 12 connected to echo pin on the ultrasonic sensor.

void setup() {
  Serial.begin(9600);
  fona.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}
void loop() {
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  fona.print("AT+CMGF=1\r");
  Serial.print("mode");
  delay(1000);
  fona.print("AT+CMGS=\"+91xxxxxxxxxx\"\r");// enter your vodafone phone number
  Serial.print("number");
  delay(1000);
  // fona.print(BinID);
  dist = (timetaken / 2) * 0.034049 ;
  bin();
}
void bin(){
  if (dist <= 10) {

    fona.print("its near full!!");
    Serial.print("Near full");
    fona.print("\r");
    Serial.print("text");
    delay(1000);
    fona.println((char)26);
    fona.println();
    Serial.println("mssg sent");
    delay(10000);
  }
  else if (dist >= 200 || dist <= 11) {
    fona.print("Half full");
    Serial.print("Half full");
    fona.print("\r");
    delay(1000);
    fona.println((char)26);
    fona.println();
    Serial.print(dist);
    delay(1000);
  }
  else {
    fona.print("Empty");
    Serial.print("Empty");
    fona.print("\r");
    delay(1000);
    fona.println((char)26);
    fona.println();
    Serial.print(dist);
    delay(1000);
  }
}

