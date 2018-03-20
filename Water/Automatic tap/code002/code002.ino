#include<NewPing.h>

#define trigger 7//attach trigger to D7 of Arduino UNO
#define echo 8//attach echo pin to D8 of Arduino UNO

#define max_distance 20//distance between sensor and oppsoite side of sink is 30cm

#define relay 10 //digital pin 8 is connected to relay

NewPing sensor(trigger,echo,max_distance);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(relay, OUTPUT);//digital pin8
  pinMode(relay,HIGH);//off by default

}

void loop() {
  // put your main code here, to run repeatedly:
int dist=sensor.ping_cm();//find the distance
Serial.print("Distance:");
Serial.println(dist);
Serial.print(" cm");
if(dist<max_distance)
{   
  digitalWrite(relay, LOW);   //on
}
else
{
  digitalWrite(relay, HIGH);    // off
}
}

