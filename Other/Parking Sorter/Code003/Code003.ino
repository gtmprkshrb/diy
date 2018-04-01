/*This project explains using Arduino as a Parking Sorter*/
/*Ultrasonic Sesnor HC-SR04 is used.*/
/*Vcc- 5V, Trigger Pin - Pin4, Echo Pin- Pin3, GND- GND*/

#define trigpin 4
#define echopin 3
#define greenpin 13
#define bluepin 12
#define redpin 11

long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
}
void reverse()
{
  if (distance < 10)
  {
    /*Red LED high*/
  digitalWrite(redpin, HIGH);
   digitalWrite(greenpin, LOW);
  digitalWrite(bluepin, LOW);
  delay(2000);
  }
  if (distance >= 300 || distance <= 10)
  {
  /*Blue LED high*/
  digitalWrite(greenpin, LOW);
  digitalWrite(bluepin, HIGH);
  digitalWrite(redpin, LOW);
  delay(2000);
  }
  else
  {
   /*Green LED high*/
  digitalWrite(greenpin, HIGH);
  digitalWrite(bluepin, LOW);
  digitalWrite(redpin, LOW);
  delay(2000);

  }

  delay(500);
}
void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration / 58.2;
  Serial.print(distance);
  Serial.println("cm");
  reverse();

}


