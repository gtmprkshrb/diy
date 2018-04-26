//This code explains how to periodically note and display humidity and temperature
//values in LCD with DHT11 sensor

#include <Wire.h>
#include <DHT.h>

#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x3F); //change the address if necessary

int measurePin = A5;
int ledPower = 12;
int dhtpin = 2;
#define DHTTYPE DHT11

unsigned int samplingTime = 280;
unsigned int deltaTime = 40;
unsigned int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;


DHT dht (2, DHT11);


void setup() {
  Serial.begin(115200);
  Wire.begin();
  pinMode(ledPower, OUTPUT);
  pinMode(dhtpin, OUTPUT);
  delay(1000);
  dht.begin();
  //lcd.home();   // initializing the LCD
  lcd.begin(16, 2); // initialize the lcd
  lcd.setBacklight(200);
  lcd.home(); lcd.clear();
  lcd.print("Hello LCD");
  delay(1000);

}

void loop() {
  delay(15000);
  digitalWrite(dhtpin, HIGH);
  digitalWrite(ledPower, LOW); // power on the LED
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin); // read the dust value

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower, HIGH); // turn the LED off
  delayMicroseconds(sleepTime);

  calcVoltage = voMeasured * (5.0 / 1024);

  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  //  dustDensity = (0.17 * calcVoltage - 0.1) * 1000;
  dustDensity = (0.17 * calcVoltage) * 1000;

  Serial.print("Raw: ");
  Serial.print(voMeasured);

  Serial.print("; - Voltage: ");
  Serial.print(calcVoltage);

  Serial.print("; - Dust Density [ug/m3]: ");
  Serial.print(dustDensity);
  Serial.println(";");

  delay(1000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  
  lcd.print("T: ");
  lcd.print(t);
  lcd.print("H: ");
  lcd.print(h);
  
  lcd.setCursor(0, 1);
  lcd.print("Dust PM2.5: ");
  lcd.print(dustDensity);
  //lcd.print(" mg/m3");
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    //return;
  }
}











