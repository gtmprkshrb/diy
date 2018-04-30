/*
 Flow sensor with solenoid and keypad for exact consumption of water
*/

#include <Wire.h>
#include <Keypad.h>

int solenoidpin = 3;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};//connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2};//connect to the column pinouts of the keypad


//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
char n;

byte sensorInterrupt = 0;
byte sensorPin       = 2;

// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
// litre/minute of flow.
float calibrationFactor = 4.5;

volatile byte pulseCount;

float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;

unsigned long oldTime;

void setup()
{
  pinMode(solenoidpin, OUTPUT);
  digitalWrite(solenoidpin, HIGH); //switch is closed-water is running

  // Initialize a serial connection for reporting values to the host
  Serial.begin(115200);
  //lcd.init();
  //lcd.init();
  //lcd.backlight();
  // Set up the status LED line as an output
  pinMode(statusLed, OUTPUT);
  digitalWrite(statusLed, HIGH);  // We have an active-low LED attached

  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);

  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
  oldTime           = 0;

  // The Hall-effect sensor is connected to pin 2 which uses interrupt 0.
  // Configured to trigger on a FALLING state change (transition from HIGH
  // state to LOW state)
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);



}

/**
   Main program loop
*/
void loop()
{

  char customKey = customKeypad.getKey();
  if (customKey) {
    n = customKey;
    Serial.println(n);
  }
  if ((millis() - oldTime) > 1000)   // Only process counters once per second
  {
    // Disable the interrupt while calculating flow rate and sending the value to
    // the host
    detachInterrupt(sensorInterrupt);

    // Because this loop may not complete in exactly 1 second intervals we calculate
    // the number of milliseconds that have passed since the last execution and use
    // that to scale the output. We also apply the calibrationFactor to scale the output
    // based on the number of pulses per second per units of measure (litres/minute in
    // this case) coming from the sensor.
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;

    // Note the time this processing pass was executed. Note that because we've
    // disabled interrupts the millis() function won't actually be incrementing right
    // at this point, but it will still return the value it was set to just before
    // interrupts went away.
    oldTime = millis();

    // Divide the flow rate in litres/minute by 60 to determine how many litres have
    // passed through the sensor in this 1 second interval, then multiply by 1000 to
    // convert to millilitres.
    flowMilliLitres = (flowRate / 60) * 1000;

    // Add the millilitres passed in this second to the cumulative total
    totalMilliLitres += flowMilliLitres;

    unsigned int frac;

    // Print the flow rate for this second in litres / minute
    Serial.print("Flow rate: ");
    Serial.print(int(flowRate));  // Print the integer part of the variable
    Serial.print(".");             // Print the decimal point
    // Determine the fractional part. The 10 multiplier gives us 1 decimal place.
    frac = (flowRate - int(flowRate)) * 10;
    Serial.print(frac, DEC) ;      // Print the fractional part of the variable
    Serial.print("L/min");
    // Print the number of litres flowed in this second
    Serial.print("  Current Liquid Flowing: ");             // Output separator
    //lcd.setCursor(0, 0);
    //lcd.print(flowMilliLitres);
    Serial.print(flowMilliLitres);
    Serial.print("mL/Sec");

    // Print the cumulative total of litres flowed since starting
    Serial.print("  Output Liquid Quantity: ");             // Output separator
    //lcd.setCursor(0, 1);
    //lcd.print(totalMilliLitres);
    Serial.print(totalMilliLitres);
    Serial.println("mL");

    // Reset the pulse counter so we can start incrementing again
    pulseCount = 0;

    // Enable the interrupt again now that we've finished sending output
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);

    /*lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CurrentUsageML:");
      lcd.print(flowMilliLitres);


      lcd.setCursor(0, 1);
      lcd.print("Total ML:");
      lcd.print(totalMilliLitres);*/

    if (n == '1' ) {//flow should not exceed 500mL
      //digitalWrite(solenoidpin, HIGH);
      //delay(1000);
      Serial.println("in 1 loop");
      if (totalMilliLitres > 500)
        digitalWrite(solenoidpin, LOW);//switch is open-flow is stopped
      delay(1000);
    }
    else if (n == '2' ) {//flow should not exceed 1000mL
      //digitalWrite(solenoidpin, HIGH);
      //delay(1000);
      Serial.println("in 2 loop");
      digitalWrite(solenoidpin, HIGH);
      if (totalMilliLitres > 1000)
        digitalWrite(solenoidpin, LOW);//switch is open-flow is stopped
      delay(1000);
    }
    else if (n == '2' ) {//flow should not exceed 1000mL
      //digitalWrite(solenoidpin, HIGH);
      //delay(1000);
      Serial.println("in 2 loop");
      digitalWrite(solenoidpin, HIGH);
      if (totalMilliLitres > 1000)
        digitalWrite(solenoidpin, LOW);//switch is open-flow is stopped
      delay(1000);
    }
    else if (n == '3' ) {//flow should not exceed 1000mL
      //digitalWrite(solenoidpin, HIGH);
      //delay(1000);
      Serial.println("in 3 loop");
      digitalWrite(solenoidpin, HIGH);
      if (totalMilliLitres > 1500)
        digitalWrite(solenoidpin, LOW);//switch is open-flow is stopped
      delay(1000);
    }
    else Serial.println("No key pressed/Invalid key.");
  }
}
/*
  Insterrupt Service Routine
*/
void pulseCounter()
{
  // Increment the pulse counter
  pulseCount++;
}



