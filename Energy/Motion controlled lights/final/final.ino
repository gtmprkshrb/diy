#include<NewPing.h>

#define trigger1 7
#define echo1 8

#define trigger2 10
#define echo2 11

#define relay 8

#define max_distance 50//distance between sensors and opposite wall is 50cm
#define check 50//time delay in ms after which sensor pings again
int count=0;

NewPing sensor1(trigger1,echo1,max_distance);
NewPing sensor2(trigger2,echo2,max_distance);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(count);
delay(500);
int ping11,ping12,ping21,ping22;
//first ping
ping11=sensor1.ping_cm();
Serial.print("Ping11:");
Serial.println(ping11);

ping12=sensor2.ping_cm();
Serial.print("Ping12:");
Serial.println(ping12);

//second ping if first pings were triggered
if(ping11!=0)
{
  while(1)
  {
    delay(check);
    ping22=sensor2.ping_cm();
    Serial.print("Ping22:");
    Serial.println(ping22);
    if(ping22!=0)
    {
      count++;
      break;
    }
  }
}
else if(ping12!=0)
{
  while(1)
  {
    delay(check);
    ping21=sensor1.ping_cm();
    Serial.print("Ping21:");
    Serial.println(ping21);
    if(ping21!=0)
    {
      count--;
      break;
    }
  }
}
if(count>0) digitalWrite(relay,LOW);//ON
else if (count==0) digitalWrite(relay,HIGH);//ON
}
