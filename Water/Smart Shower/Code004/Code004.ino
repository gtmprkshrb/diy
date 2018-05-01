
int trig = 12;
int echo = 11;

#define solenoid 3

#define Buzzer  13

byte sensorInterrupt = 0;
byte sensorPin       = 2; //digital pin 2
float calibrationFactor = 6.5;

volatile byte pulseCount;

float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;

unsigned long oldTime;

void setup()
{
  int error;

  Serial.begin(115200);


  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);

  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
  oldTime           = 0;
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  pinMode(solenoid, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop()
{
  pinMode(trig, OUTPUT);
  long duration, Cm;
  //long microsecondsToCentimeters(float microseconds);
  //long microseconds;
  digitalWrite (trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  Cm = microsecondsToCentimeters(duration);
  Serial.print("The distance is ");
  Serial.println(Cm);
  if (Cm > 15)
  {
    digitalWrite(solenoid, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
  }
  else
  {
    digitalWrite(solenoid, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  }
  if ((millis() - oldTime) > 1000)   // Only process counters once per second
  {
    detachInterrupt(sensorInterrupt);  // Disable the interrupt while calculating flow rate and sending the value to
    // the host

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
    Serial.print(flowMilliLitres);
    Serial.print("mL/Sec");

    // Print the cumulative total of litres flowed since starting
    Serial.print("  Output Liquid Quantity: ");             // Output separator
    Serial.print(totalMilliLitres);
    Serial.println("mL");
    if (totalMilliLitres > 1000)
    {
      digitalWrite(Buzzer, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(2000);                       // wait for a second
    }
    else
    {
      digitalWrite(Buzzer, LOW);    // turn the LED off by making the voltage LOW
      // wait for a second
    }

    pulseCount = 0;  // Reset the pulse counter so we can start incrementing again

    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);   // Enable the interrupt again now that we've finished sending output
  }
}

void pulseCounter()
{
  // Increment the pulse counter
  pulseCount++;
}

long microsecondsToCentimeters (long microseconds)
{
  return microseconds / 29 / 2;
}

