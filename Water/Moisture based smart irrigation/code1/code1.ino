//soil moisture sensor
#define soilMoisture A0 //connect analog pin of soil moisture sensor to A0 of Arduino                   
//for calibration
#define high 1025 //maximum value detected by soil moisture sensor
#define low 10 //minimum value detected by soil moisture sensor

//flow sensor
#define flowSensor 2//connect data pin of flow sensor to D2 of Arduino
#define reqWater 2000//flow is stopped after 2000 mL
byte sensorInterrupt = 0;
// The hall-effect flow sensor outputs approximately 7.5 pulses per second per
// litre/minute of flow.
float calibrationFactor = 7.5;
volatile byte pulseCount;  
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
unsigned long oldTime;
unsigned long moisture;
float percentage;

#define relay 8//connect data pin of relay to D8 of Arduino

void setup()
{
   // Initialize a serial connection for reporting values to the host
  Serial.begin(115200);

  pinMode(soilMoisture,INPUT);
  pinMode(flowSensor, INPUT);
  digitalWrite(flowSensor, HIGH);
  pinMode(relay, OUTPUT);
  pinMode(relay,HIGH);//off
  
  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
  oldTime           = 0;
  moisture          =0;
  percentage=100;
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
}

void loop()
{
  if(flowRate<16)//read soil moisture only when no flow
  {
   totalMilliLitres  = 0;
   moisture=analogRead(soilMoisture);
   Serial.println(moisture);
   percentage=100-(moisture*0.0975);//express as a percentage
   Serial.println(percentage);
   delay(3000);
  }
  if(percentage<=30)//start flow if soil moisture is greater than 30 percent
  {
  if((millis() - oldTime) > 1000)    // Only process counters once per second
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
    Serial.print("L/min");
    Serial.print("\t");       // Print tab space

    // Print the cumulative total of litres flowed since starting
    Serial.print("Output Liquid Quantity: ");        
    Serial.print(totalMilliLitres);
    Serial.println("mL"); 

    // Reset the pulse counter so we can start incrementing again
    pulseCount = 0;
    
    // Enable the interrupt again now that we've finished sending output
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }
  }
    if(totalMilliLitres>reqWater)
{   
  digitalWrite(relay, LOW);   //off
  delay(2000);                       // wait for a second
}
else
{
  digitalWrite(relay, HIGH);    // on                         // wait for a second
}
}

void pulseCounter()
{
  // Increment the pulse counter
  pulseCount++;
}

long microsecondsToCentimeters (long microseconds)
{
   return microseconds /29 /2;
  }

