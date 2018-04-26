//This code helps to automatically switch on/off light based on distance of the person.
//distance sensor, One channel Relay and LED Light are used.

#define trigPin 12 // digital pin 12
#define echoPin 11 //digital pin 11
int relay = 3;    //digital pin 3

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  delay(100);
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  Serial.print("Distance in CM:");
  Serial.println(dist);
  if (dist < 20)  // Change the distance value here.
  { 
    digitalWrite( relay, LOW); // Relay LOW, Light ON
    delay(10000);
  }
  else {
    digitalWrite( relay, HIGH); // Relay HIGH, Light OFF
  }
  delay(500);
}

