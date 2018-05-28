#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x3F);
#include<DHT.h>

DHT dht (2, DHT22);
#define ONE_WIRE_BUS 7

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float tempC = 0;
int dhtpower = 9;
void setup() {
  sensors.begin();
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  dht.begin();
  lcd.print("Hello");
  delay(1000);
  Serial.begin(9600);
  pinMode(dhtpower, INPUT);
  digitalWrite(dhtpower, HIGH);
}
void loop(){
  dsb();
  dht22();
}
void dsb() {
  sensors.requestTemperatures();
  tempC = sensors.getTempCByIndex(0);
  delay(1000);
  Serial.println(tempC);
  
  lcd.setCursor(0, 0);
  lcd.print("BinTemp:");
  lcd.print(tempC);
  lcd.print("*C");
}
void dht22() {
  delay(2000);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  lcd.setCursor(0,1);
  lcd.print("AmbientTemp:");
  lcd.print(temperature);
  lcd.print(" *C");
}

