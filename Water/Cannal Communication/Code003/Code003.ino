/*This code explains easy irrigation in farms with help of moisture, rain sensor and
   GSM 800 Module where user receives SMS if rain level is high and moisture is wet
   Use Vodafone SIM card
*/
#include <Adafruit_FONA.h>
#include <SoftwareSerial.h>

int sensorpin = A1; //  moisture sensor
int rainpin = A2; //rain sensor

#define FONA_RX 5
#define FONA_TX 6
#define FONA_RST 4
SoftwareSerial fona (FONA_TX, FONA_RX);

char replybuffer[255];

void setup() {
  Serial.begin(9600);
  fona.begin(9600);
  pinMode(sensorpin, INPUT);
  pinMode(rainpin, INPUT);

}
void loop() {
  rain();
  soil();
}
void rain() {
  int rainSenseReading = analogRead(rainpin);
  Serial.println(rainSenseReading); // serial monitoring message
  delay(250);// rain sensing value from 0 to 1023 : from heavy rain - no rain.

  if (rainSenseReading > 350 && rainSenseReading < 1000) {

    fona.print("its Raining!");
    Serial.print("its Raining!");
    fona.print("\r");
    Serial.print("text");
    delay(1000);
    fona.println((char)26);
    fona.println();
    Serial.println("mssg sent");
    delay(10000);
  }
  else if (rainSenseReading < 350) {

    fona.print("Half rain");
    Serial.print("Half rain");
    fona.print("\r");
    delay(1000);
    fona.println((char)26);
    fona.println();
    
    delay(1000);
  }
  else {
    fona.print("No rain");
    Serial.print("No rain ");
    fona.print("\r");
    delay(1000);
    fona.println((char)26);
    fona.println();
    
    delay(1000);
  }
}
void soil() {
  int value = analogRead(sensorpin);
  Serial.println(value);
  delay(2000);
  
  if ( value < 400)
  {
    Serial.println("Wet soil");
    fona.print("Wet soil, no water required");
    fona.print("\r");
    delay(1000);
    fona.println((char)26);
    fona.println();

  }
  else
  {
    Serial.println("Dry soil"); // Greater than 400
    fona.print("Dry soil, water required");
    fona.print("\r");
    delay(1000);
    fona.println((char)26);
    fona.println();
    delay(2000);
  }
}




