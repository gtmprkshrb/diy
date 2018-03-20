#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x3F);  // set the LCD address that was displayed

int show;

void setup()
{
  int error;

  digitalWrite(2,HIGH);//VCC connection

  Serial.begin(115200);
  Serial.println("LCD...");

  while (! Serial);

  Serial.println("Dose: check for LCD");

  // See http://playground.arduino.cc/Main/I2cScanner
  Wire.begin();
  Wire.beginTransmission(0x3F);// set the LCD address that was displayed
  error = Wire.endTransmission();
  Serial.print("Error: ");
  Serial.print(error);

  if (error == 0) {
    Serial.println(": LCD found.");

  } else {
    Serial.println(": LCD not found.");
  } // if

  lcd.begin(16, 2); // initialize the lcd
} // setup()

void loop()
{
    lcd.setBacklight(255);
    lcd.setCursor(0, 0);
    lcd.print("Total output:");
    lcd.setCursor(0, 1);
    lcd.print("L");
} // loop()
