//This is the combined code of DHT sensor & Sharp dust sensor and values will be displayed on LCD screen
//Data can be seen live on Dashboard

#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino 
#include <PubSubClient.h>
#include<Wire.h>

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include "DHT.h"
#include <LiquidCrystal_I2C.h>

//DHT Section setup
#define DHTPIN D6
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
float h, t;
//#define WLAN_SSID  "//*your ssid here" // Please type your Wifi SSID name 
//#define WLAN_PASS  "//password here" // Please type your Wifi password 
#define BROKER_IP  "13.71.3.239" // The IP of the machine where the broker is running
#define BROKER_PORT 1883
#define CLIENT_NAME "Air"
WiFiClient wifiClient;
PubSubClient mqttClient(BROKER_IP, BROKER_PORT, wifiClient);

//LCD
LiquidCrystal_I2C lcd(0x3F, 16, 2); // check the lcd i2c number
//LiquidCrystal_I2C lcd(0x27, 16, 2);

//Sharp Dust Sensor
int measurePin = A0;
int ledPower = D0;
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
const int numReadings = 5;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
 
  dht.begin();
  lcd.init();   // initializing the LCD
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Setting Up");
  lcd.clear();
  pinMode(ledPower, OUTPUT);
  pinMode(measurePin, OUTPUT);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  dustdata();
  temp();
  showonlcd();
  senddata();
  delay(15000);
  lcd.clear();
}

//Functions written now on

void temp() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.println();
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}

void dustdata() {


  digitalWrite(ledPower, LOW); // power on the LED
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin); // read the dust value

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower, HIGH); // turn the LED off
  delayMicroseconds(sleepTime);

  // 0 - 5.0V mapped to 0 - 1023 integer values
  calcVoltage = voMeasured * (3.3 / 1024);

  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  dustDensity = (0.17 * calcVoltage - 0.1) * 1000;

  Serial.print("Raw Signal Value (0-1023): ");
  Serial.print(voMeasured);

  Serial.print(" - Voltage: ");
  Serial.print(calcVoltage);

  Serial.print(" - Dust Density: ");
  Serial.println(dustDensity);


  total = total - readings[readIndex];
  // read from the sensor:
  //readings[readIndex] = analogRead(inputPin);
  readings[readIndex] = dustDensity;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits

  if (average < 0) {
    average = -0.833 * average ;
    Serial.println(average);
  }
  else {
    Serial.println(average);
  }
}

void senddata() {
  if (!mqttClient.connected())
  {
    connectToWiFi();
    connectToBroker();
  }
  mqttClient.loop();
  publishFloatValue(t, "RB/AQM/Breathe/001/Temp");
  publishFloatValue(h, "RB/AQM/Breathe/002/Hum");
  publishFloatValue(average, "RB/AQM/Breathe/003/Dust");
}

void connectToWiFi(){
  WiFiManager wifiManager;
  wifiManager.setTimeout(60);

  if (!wifiManager.autoConnect("SetupWifionAQM")) {
    Serial.println("failed to connect and hit timeout");
    delay(3000);
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(5000);
  }
  //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)"); 
}
void connectToBroker() {

  Serial.println("Connecting to broker");
  while (!mqttClient.connect(CLIENT_NAME))
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected to broker!");
}

char msg[50];
void publishFloatValue(float value, char* topic)
{
  if (isnan(value))
  {
    Serial.println("Invalid value!");
    return;
  }

  Serial.println("Publishing a new value");
  ftoa(msg, value);
  Serial.println(msg);
  mqttClient.publish(topic, msg);
}

char *ftoa(char *buffer, float f)
{
  char *returnString = buffer;
  long integerPart = (long)f;
  itoa(integerPart, buffer, 10);
  while (*buffer != '\0') buffer++;
  *buffer++ = '.';
  long decimalPart = abs((long)((f - integerPart) * 100));
  itoa(decimalPart, buffer, 10);
  return returnString;
}

void showonlcd() {
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);
  lcd.print("C H ");
  lcd.print(h);
  lcd.setCursor(0, 1);
  lcd.print("PM2.5: ");
  lcd.print(average);

  if (average > 1 && average  <= 50) {
    lcd.print (" GOOD ");
  }
  else if (average >= 51 && average <=100) {
    lcd.print ("MODERATE");
  }
    else if (average >101){
      lcd.print("  BAD  ");
  }
}
