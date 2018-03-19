#include<NewPing.h>

#define trigger 7//attach trigger to D7 of Arduino UNO
#define echo 8//attach echo pin to D8 of Arduino UNO

#define max_distance 200//distance between sensor and bottom of tank is 200cm

NewPing sensor(trigger,echo,max_distance);

//rgb
#define RED 5//red pin of led attached to D4 of Arduino UNO
#define GREEN 6//green pin of led attached to D5 of Arduino UNO

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

if(dist<50)//out of 200
{
  digitalWrite(GREEN,LOW);
  digitalWrite(RED,HIGH);//red light glows indicating that the tank is nearly full
}
else if(dist<100)//out of 200
{
digitalWrite(RED,HIGH);
digitalWrite(GREEN,HIGH);//yellow is a 50-50 mix of green and red indicating that the tank is halfway full
}
else
{
  digitalWrite(GREEN,HIGH);//green light glows indictaing the tank is close to empty
  digitalWrite(RED,HIGH);
}
}

