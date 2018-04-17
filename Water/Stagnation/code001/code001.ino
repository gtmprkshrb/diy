#include<NewPing.h>

#define trigger 12//attach trigger to D7 of Arduino UNO
#define echo 11//attach echo pin to D8 of Arduino UNO

#define max_distance 100//distance between sensors and opposite side is 100cm

NewPing sensor(trigger,echo,max_distance);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int dist=sensor.ping_cm();//find the distance
Serial.print("Distance:");
Serial.println(dist);
Serial.print(" cm");
}

