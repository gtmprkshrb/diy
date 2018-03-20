#include<NewPing.h>

#define trigger 7//attach trigger to D7 of Arduino UNO
#define echo 8//attach echo pin to D8 of Arduino UNO

#define max_distance 200//distance between sensors and opposite side of bin is 200cm

#define relay 8//digital pin 8

NewPing sensor(trigger,echo,max_distance);//initialising sensor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(relay,OUTPUT);
  pinMode(relay,LOW);//default off
}

void loop() {
  // put your main code here, to run repeatedly:
int dist=sensor.ping_cm();//find the distance
Serial.print("Distance:");
Serial.println(dist);
Serial.print(" cm");
if(dist<=100)//threshold distance determined by testing
{
  digitalWrite(relay,HIGH);//on
  delay(20000);//delay for 20s
}
else digitalWrite(relay,LOW);//off
}

