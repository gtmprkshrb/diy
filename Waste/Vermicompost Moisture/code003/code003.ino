#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x3F);  // set the LCD address that was displayed

int show;

#define soilMoisture1 A0
#define soilMoisture2 A1 //connect analog pin of soil moisture sensor2 to A1 of Arduino                   
//calibration
//maximum value detected(dry) 1025
//minimum value detected(wet) 10
//percentage of moisture= 100-(detected/maximum*100)
//100/maximum=100/1025=0.0975

unsigned long moisture1,moisture2, moisture;
float percentage;

void setup() {
  // put your setup code here, to run once:
   // Initialize a serial connection for reporting values to the host
  int error;

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
  lcd.setBacklight(255);

  pinMode(soilMoisture1,INPUT);
  pinMode(soilMoisture2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   moisture1=analogRead(soilMoisture1);//read input from pin A0(soilMoisture)
   moisture2=analogRead(soilMoisture2);//read input from pin A1(soilMoisture)
   moisture=(moisture1+moisture2)/2;//taking the average for a more reliable result
   Serial.print("Moisture: ");
   Serial.print(moisture);
   Serial.print("\t");
   percentage=100-(moisture*0.0975);//express as a percentage
   Serial.print("Percentage: ");
   Serial.print(percentage);
   Serial.println("%");
   delay(3000);
   lcd.setCursor(0, 0);
   lcd.print("Moisture:");
   lcd.print(percentage);
   lcd.print("%");
   lcd.setCursor(0, 1);
   if (percentage<30)   lcd.print("TOO DRY");
   else if (percentage>70)  lcd.print("TOO WET");
   else lcd.print("PERFECT");
}
