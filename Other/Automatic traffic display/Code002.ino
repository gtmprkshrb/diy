/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int greenPin = 9;
int redPin = 10;
int bluePin = 11;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
digitalWrite(greenPin,HIGH);
digitalWrite(redPin,LOW);
digitalWrite(bluePin,LOW);
delay(5000);
  
digitalWrite(redPin,HIGH);
digitalWrite(greenPin,LOW);
digitalWrite(bluePin,LOW);
delay(2000);

digitalWrite(bluePin,HIGH);
digitalWrite(greenPin,LOW);
digitalWrite(redPin,LOW);
delay(5000);
}
