//testing red and green light of rbg led
#define RED 5//red pin of led attached to D5 of Arduino UNO
#define GREEN 6//green pin of led attached to D6 of Arduino UNO

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//testing red light
digitalWrite(RED,HIGH)//red light glows indicating that water will overflow
delay(10000)//wait for 10s
digitalWrite(RED,LOW)//red light switches off
delay(10000)//wait for 10s

//testing green light
digitalWrite(GREEN,HIGH)//green light glows
delay(10000)//wait for 10s
digitalWrite(GREEN,LOW)//green light switches off
delay(10000)//wait for 10s
}
}

