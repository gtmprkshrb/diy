//testing rbg led
#define RED 5//red pin of led attached to D4 of Arduino UNO
#define GREEN 6//green pin of led attached to D5 of Arduino UNO

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//testing green light
digitalWrite(GREEN,HIGH);//green light glows indicated bin is not yet full
delay(10000);//wait for 10s
digitalWrite(GREEN,LOW);//green light switches off
delay(10000);//wait for 10s

//testing yellow light
digitalWrite(RED,HIGH);
digitalWrite(GREEN,HIGH);//yellow is a 50-50 mix of green and red
delay(10000);//wait for 10s
digitalWrite(RED,LOW);
digitalWrite(GREEN,LOW);
delay(10000);//wait for 10s

//testing red light
digitalWrite(RED,HIGH);//red light glows 
delay(10000);//wait for 10s
digitalWrite(RED,LOW);//red light switches off
delay(10000);//wait for 10s
}

