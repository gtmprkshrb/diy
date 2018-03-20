#define RED 5//red pin of led attached to D5 of Arduino UNO
#define GREEN 6//green pin of led attached to D6 of Arduino UNO

#include<NewPing.h>

#define trigger 7//attach trigger to D7 of Arduino UNO
#define echo 8//attach echo pin to D8 of Arduino UNO

#define max_distance 20//distance between sensors and opposite side of bin is 20cm

NewPing sensor(trigger,echo,max_distance);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int dist=sensor.ping_cm();//find the distance
Serial.print("Distance:");
Serial.println(dist);
Serial.print(" cm");

if(dist<=5)//trash fills the distnace between the sensor and the opposite side of the bin
{
  digitalWrite(RED,HIGH);//red light glows indicating that it must be emptied 
}
else
{
  digitalWrite(GREEN,HIGH);//green light glows indicated bin is not yet full
}
delay(30000);//wait 30s
}

