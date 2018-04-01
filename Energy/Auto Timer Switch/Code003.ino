// Date and time functions using just software, based on millis() & timer

#include <Wire.h>
#include "RTClib.h"

RTC_Millis rtc;
int relay = 4;
int power = 12;
void setup () {
  //Serial.begin(57600);
  // following line sets the RTC to the date & time this sketch was compiled
  rtc.begin(DateTime(__DATE__, __TIME__));
  pinMode(relay, OUTPUT);
  pinMode(power, OUTPUT);
  digitalWrite(power, HIGH);
}

void loop () {
  DateTime now = rtc.now();

  /*Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);*/

  if (now.hour() == 14 && now.minute() >= 58 && now.minute() <= 56) {
    digitalWrite(relay, HIGH);
    Serial.println("ALARM ON");

  } else
  {
    digitalWrite(relay, LOW);
    Serial.println("ALARM OFF");
  }

  //Serial.println();
  delay(3000);
}
