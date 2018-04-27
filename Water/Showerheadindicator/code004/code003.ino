/*This code shows the working of smart water usage Water flow sensor,RGB LED and Solenoid valve.
   RGB LED comes in two types. Check the connection before testing.
   Connected the long leg pin of RGB LED either to Ground or 5v depending on their type.
*/
int r = 7; //r- red,  digital pin 7
int g = 8; // g- green, digital pin 8
int b = 9; // b- blue, digital pin 9

int solenoid valve = 3; //digital pin 3

int pulsecount = 0;;
byte sensorInterrupt = 0;
byte sensorPin       = 2; //digital pin 2
float calibrationFactor = 7.5;

volatile byte pulseCount;

float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;

unsigned long oldTime;


void setup() {
  Serial.begin(9600);
  pinMode(solenoidpin, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);

  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
  oldTime           = 0;
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
}

void loop() {
  if ((millis() - oldTime) > 1000)   // Only process counters once per second
  {

    detachInterrupt(sensorInterrupt);
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    oldTime = millis();
    flowMilliLitres = (flowRate / 60) * 1000;
    totalMilliLitres += flowMilliLitres;
    unsigned int frac;
    Serial.print("Flow rate: ");
    Serial.print(int(flowRate));  // Print the integer part of the variabley
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
    pulseCount = 0;
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }

  if (totalMilliLitres > 0 && totalMilliLitres < 500) {
    green();
  }
  else if (totalMilliLitres > 500 && totalMilliLitres < 1000) {
    blue();
  }
  else if (totalMilliLitres > 1000) {
    red();
    digitalWrite(solenoidPin, HIGH);    //Switch Solenoid ON, Water OFf
    delay(1000);                      //Wait 1 Second
    
  }

}

void red() {
  digitalWrite(r, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
}

void green() {
  digitalWrite(g, LOW);
  digitalWrite(r, HIGH);
  digitalWrite(b, HIGH);
}

void blue() {
  digitalWrite(b, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(r, HIGH);
}

void pulseCounter()
{
  // Increment the pulse counter
  pulseCount++;
}

