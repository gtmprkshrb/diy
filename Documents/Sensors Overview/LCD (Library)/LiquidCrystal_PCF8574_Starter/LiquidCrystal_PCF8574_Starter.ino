#include <LiquidCrystal_PCF8574.h>

int address = 0x27;
//int address = 0x3F;

LiquidCrystal_PCF8574 lcd(address);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  int error;

  Serial.begin(115200);
  Serial.println("LCD...");

  while (! Serial);

  Serial.println("Dose: check for LCD");

  lcd.begin(16, 2); // initialize the lcd
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  lcd.print("Hello LCD");
  delay(1000);
} // setup()

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("*** first line.");
  lcd.setCursor(0, 1);
  lcd.print("*** second line.");
  delay(2000);
} // loop()
