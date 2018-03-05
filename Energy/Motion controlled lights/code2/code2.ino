#include<NewPing.h>

#define trigger1 7//attach trigger to D7 of Arduino UNO
#define echo1 8//attach echo pin to D8 of Arduino UNO
#define trigger2 10//attach trigger to D7 of Arduino UNO
#define echo2 11//attach echo pin to D8 of Arduino UNO

#define max_distance 20//distance between sensors and opposite side of bin is 20cm

NewPing sensor1(trigger1,echo1,max_distance);
NewPing sensor2(trigger2,echo2,max_distance);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int dist1=sensor1.ping_cm();//find the distance
Serial.print("Distance1:");
Serial.println(dist1);
Serial.print(" cm");
int dist2=sensor2.ping_cm();//find the distance
Serial.print("Distance2:");
Serial.println(dist2);
Serial.print(" cm");
}

