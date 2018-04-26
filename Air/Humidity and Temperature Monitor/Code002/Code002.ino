#include <DHT.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27); //change the adress to 0x3F if necessary

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("With Breadboard");
  dht.begin();
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  lcd.print("Hello ARCHANA");
  delay(1000);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %\t");
  Serial.println("Temperature: ");
  Serial.println(t);
  Serial.print(" *C ");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp is (C)");
  lcd.print(t);
  lcd.setCursor(0, 1);
  lcd.print("Himidity is (%t)");
  lcd.print(h);

  if (t < 30)
  {
    lcd.setCursor(0, 2);
    lcd.print("Its warm");
  }
  else
  {
    lcd.setCursor(0, 2);
    lcd.print("Its not warm");
  }
}

