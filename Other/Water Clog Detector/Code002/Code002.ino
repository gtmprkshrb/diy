/*this code exaplins the real time detection and display of water clog in appartment/houses
   Uses LCD and moisture sensor and monitors periodically
*/
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27); // address of LCD, change to 0x3F if needed

#define sensorpin A1

void setup() {
  Serial.begin (9600);
  pinMode(sensorpin, OUTPUT);
  lcd.home();
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home();
  lcd.print("Hello ");
  delay(1000);
  lcd.clear();

}
void loop() {
  delay(500);
  int sensorValue = analogRead(sensorpin);
  Serial.println(sensorValue);
  if (sensorValue  <= 400) //change the value if necessary
  {
    lcd.setCursor(0, 0);
    lcd.print("Water Clogged!!!");
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Water Not Clogged !!!");
  }

  delay(1000);
}

