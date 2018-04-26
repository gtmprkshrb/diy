#include<DHT.h>

DHT dht (2, DHT11);
void setup() {
  Serial.begin(9600);
  Serial.print("DHT test");
  dht.begin();
}

void loop() {

  delay(2000);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("\n Humidity =");
  Serial.print(humidity);
  Serial.print("% \n");
  Serial.print("Temperature =");
  Serial.print(temperature);
  Serial.print(" *C");
 
}
