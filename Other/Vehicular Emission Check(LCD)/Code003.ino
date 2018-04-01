#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27); // address of LCD
#define lcdpower 9

void setup() {
  // put your setup code here, to run once:
  pinMode(lcdpower, OUTPUT);

  digitalWrite(lcdpower, HIGH);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home();
  lcd.print("Hello ");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  int val;
  val = analogRead(1);
  Serial.println(val, DEC);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("CO Level");
  lcd.setCursor(0, 1);
  lcd.print(val, DEC);
  if (val > 300) {
    lcd. setCursor(4, 2);
    lcd.print("Do emission Test");
  }
  else {
    lcd. setCursor(4, 2);
    lcd.print("Safe");
  }
}





