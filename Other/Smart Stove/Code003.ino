//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugge`d into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

int sensor_pin = A0;
int Buzzer = 13;

void setup(void)
{
  Serial.begin(9600); //Begin serial communication
  Serial.println("This is the Smart Stove Solution"); //Print a message
  Serial.println("Reading From the TILT Sensor ...");
  delay(2000);
  pinMode(Buzzer, OUTPUT);

  sensors.begin();
}

void loop(void)
{ 
int value = analogRead(sensor_pin);
  //value = value / 10;
  if (value>300)
    {
     Serial.println ("Stove is On");
     Serial.println ("Detecting the temperature near the burner");
     Serial.println ("Wait for 15 Seconds");

     delay(15000);
      // Send the command to get temperatures
    sensors.requestTemperatures();  
    Serial.print("Temperature is: ");
    Serial.println(sensors.getTempCByIndex(0)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
    int Temp=sensors.getTempCByIndex(0);
      if (Temp>35)
         { 
            Serial.println ("Temperature Detected");
            digitalWrite(Buzzer, LOW);

         }
      else
      {
            Serial.println ("HIGH Temperature not detected");
            Serial.println ("Stove is on but It is not lit(Indicating Gas leakage)");
            digitalWrite(Buzzer, HIGH);
      }
    }
  else
  {
            Serial.println("Stove is Off");
            digitalWrite(Buzzer, LOW);
            delay(1000);
  }  
}
