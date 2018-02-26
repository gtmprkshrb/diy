//soil moisture sensor
#define soilMoisture A0 //connect analog pin of soil moisture sensor to A0 of Arduino                   
//calibration
//maximum value detected(dry) 1025
//minimum value detected(wet) 10
//percentage of moisture= 100-(detected/maximum*100)
//100/maximum=100/1025=0.0975

unsigned long moisture;
float percentage;

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x3F);  // set the LCD address that was displayed

int show;

void setup()
{
  int error;

  digitalWrite(2,HIGH);//VCC connection

  Serial.begin(115200);
  Serial.println("LCD...");

  while (! Serial);

  Serial.println("Dose: check for LCD");

  // See http://playground.arduino.cc/Main/I2cScanner
  Wire.begin();
  Wire.beginTransmission(0x3F);// set the LCD address that was displayed
  error = Wire.endTransmission();
  Serial.print("Error: ");
  Serial.print(error);

  if (error == 0) {
    Serial.println(": LCD found.");

  } else {
    Serial.println(": LCD not found.");
  } // if

  lcd.begin(16, 2); // initialize the lcd

    pinMode(soilMoisture,INPUT);

} // setup()

void loop()
{
    // put your main code here, to run repeatedly:
   moisture=analogRead(soilMoisture);//read input from pin A0(soilMoisture)
   Serial.print("Moisture: ");
   Serial.print(moisture);
   Serial.print("\t");
   percentage=100-(moisture*0.0975);//express as a percentage
   Serial.print("Percentage: ");
   Serial.print(percentage);
   Serial.println("%");
   lcd.setBacklight(255);
   lcd.setCursor(0, 0);
   if(percentage>=20)
   {
    lcd.print("WET WASTE!");
   }
   else lcd.print("NO WET WASTE :)");
   delay(900000)//delay for 15 min
} // loop()
