/*This code explains the controlling appliance based on time.
 * One channel Relay is connected to NO terminal.
 * Uses One channel relay, RTC sensor and Light/fan
 */

#include <Wire.h>
#include "RTClib.h"

RTC_Millis rtc;
int relay = 3;

void setup () {
  //Serial.begin(57600);
  // following line sets the RTC to the date & time this sketch was compiled
  rtc.begin(DateTime(__DATE__, __TIME__));
  pinMode(relay, OUTPUT);
}

void loop () {
  DateTime now = rtc.now();
  if (now.hour() == 14 && now.minute() >= 58 && now.minute() <= 56) //change now.hour(), now.minute() here
  {
    digitalWrite(relay, HIGH); //Relay HIGH, Light/fan OFF.
    Serial.println("ALARM ON");

  } else
  {
    digitalWrite(relay, LOW);
    Serial.println("ALARM OFF"); // Relay LOW, Light/fan ON
  }
  delay(3000);
}
