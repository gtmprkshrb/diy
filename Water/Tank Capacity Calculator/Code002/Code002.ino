/*for a circular overhead tank use pi *r*r formula.
 * for rectangular tank , use l*b* dist
 * change accordingly.
 */

#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);//change to 0x3F if necessary
 
#define trigPin 12
#define echoPin 11

 float r= 3.5;  //change in cm
 
//int breadthoftank = 9; //change in cm for rectangular tank
//int lengthoftank = 9; //change in cm for rectangular tank
int tankcapacity;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(lcdpower, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(lcdpower, HIGH);
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home(); lcd.clear();
  lcd.print("Hello LCD");
  delay(1000);
  lcd.clear();
}

void loop() {
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  if (dist >= 300 || dist <= 0) {
    Serial.println("Out Of Range");
  }
  else {
    Serial.println("Distance in CM: ");
    Serial.print(dist);
  }
  delay(500);

  tankcapacity = (3.14 * r * r * (dist));//..for circular tank
  //tankcapacity = (lengthoftank * breadthoftank *  (dist)); ..for rectangular tank
  Serial.println(tankcapacity);
  lcd.setCursor(0, 0);
  lcd.print("Tank Capacity (lt)");
  lcd.setCursor(0, 1);
  lcd.print(tankcapacity);


}
