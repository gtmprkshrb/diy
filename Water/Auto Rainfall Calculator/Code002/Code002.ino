/*this code explains the functionality of calculating rainfall in terrace
 * Refer to the formula used here
 * rainrecievedlits = ((lengthofroof * breadthofroof * runoffcoeff) * (distancefromsensortofloor - dist) * 0.01);
 * Uses LCD I2c and Distance sensor
 */

#include <LiquidCrystal_PCF8574.h>

#define trigPin 12
#define echoPin 11


float lengthofroof = 22.2; //in centimeters
float breadthofroof = 20.5; //in centimeters
float runoffcoeff = 0.8;
float distancefromsensortofloor = 30.0; // in centimeters 
int rainrecievedlits;
int timetaken, dist;

LiquidCrystal_PCF8574 lcd(0x27);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2); // initialize the lcd
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  lcd.print("Hello LCD");
  delay(1000);

}

void loop() {

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  Serial.println("Distance in CM: ");
  Serial.println(dist);
  delay(500);

  rainrecievedlits = ((lengthofroof * breadthofroof * runoffcoeff) * (distancefromsensortofloor - dist) * 0.01);
  Serial.println(rainrecievedlits);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dist(cm): ");
  lcd.print(dist);
  lcd.setCursor(0, 1);
  lcd.print("Rain (Lits) now: ");
  lcd.print(rainrecievedlits);

}

