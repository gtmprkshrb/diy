/*This code helps to find the mositure levels at two different points in lakes 
 * with help of Two soil moisture sensors, LCD I2C and a PVC pipe to test.
 */

#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x3F); //change address to 0x27 if 0x3F is not detected.

int sensor0 = A0;
int reading0;
int sensor1 = A1;
int reading1;
int sensorpower0 = 12;
int sensorpower1 = 11;
unsigned int threshold = 400;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor0, INPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensorpower0, OUTPUT);
  digitalWrite(sensorpower0, HIGH);
  pinMode(sensorpower1, OUTPUT);
  digitalWrite(sensorpower1, HIGH);
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home(); lcd.clear();
  lcd.print("Hello LCD");
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  reading0 = analogRead (sensor0);
  Serial.println(reading0);
  reading1 = analogRead (sensor1);
  Serial.println(reading1);
  delay(1000);
  lcd.setCursor(0, 0);

  if (sensor0 > threshold) {
    lcd.print("Sensor0= dry");
  }
  else {
    lcd.print("Sensor0= wet");
  }

  if (sensor1 > threshold) {
    lcd.print("Sensor1= dry");
  }
  else {
    lcd.print("Sensor1= wet");
  }
}
