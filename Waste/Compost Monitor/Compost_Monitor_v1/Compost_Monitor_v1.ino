#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino 

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#include <OneWire.h>
#include <DallasTemperature.h>

//DHT Section setup

#define DHTPIN D4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
float h, t, bin1t;

//One wire
#define ONE_WIRE_BUS D8 // DS18B20 on arduino pin2 corresponds to D4 on physical board
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

//Server Setup Section
//const char* server = "52.66.114.79";
//String apiKey = "MEUJAFLOQP0WBWFK";//AQM channel 4
WiFiClient client;

//LCD
LiquidCrystal_I2C lcd(0x3F, 16, 2);
//LiquidCrystal_I2C lcd(0x27, 16,2);

const char* host = "api.pushingbox.com";
String devidenti = "v83D5D55FC328535";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
  lcd.init();   // initializing the LCD
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Setting Up");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Compost Monitor");
  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;
  wifiManager.setTimeout(60);

  if (!wifiManager.autoConnect("SetupWifiForCompost")) {
    Serial.println("failed to connect and hit timeout");
    delay(3000);
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(5000);
  }
  //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)");
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  onewiretemp();
  dhttemp();
  showonlcd();
  senddata();
  delay(15000);
  lcd.clear();
}

//Functions written now on

void dhttemp() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.println();
}

void onewiretemp() {
  DS18B20.requestTemperatures();
  bin1t = DS18B20.getTempCByIndex(0);
  Serial.println(bin1t);
  delay(1000);
}

void senddata() {
  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
  String url = "/pushingbox?";
  url += "devid=";
  url += devidenti;
  //url += "&value=" + String(data);
  url += "&dhttemp=" + String(h);
  url += "&dhthum=" + String(t);
  url += "&bin1t=" + String(bin1t);
  //url += "&bin2t=" + String(bin2t);
  //url += "&bin3t=" + String(bin3t);

  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
    Serial.print("Data Sent!");
  }

  Serial.println();
  Serial.println("closing connection");
  delay(5000);
  delay(90000);
}


void showonlcd() {
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);
  //lcd.setCursor(0,);
  lcd.print("C H:");
  lcd.print(h);
  lcd.setCursor(0, 1);
  lcd.print("Bin Temp(C):");
  lcd.print(bin1t);
}
