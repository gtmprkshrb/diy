/*this code exaplins the real time detection and display of potholes in road while
 * on car/vehicle. Uses LCD and Distance sensor
 */
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27); // address of LCD, change to 0x3F if needed

#define trigPin 12
#define echoPin 11

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  if (dist  <= 17) //change the value if necessary
  {
    Serial.print(dist);
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.print("Pothole Detected!!!");
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Pothole Not detected !!!");
  }

  delay(1000);
}





