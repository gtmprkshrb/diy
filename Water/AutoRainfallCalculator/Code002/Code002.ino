#define trigPin 7
#define echoPin 8

float lengthofroof = 22.2; //change in meters
float breadthofroof = 20.5; //change in meters
float runoffcoeff = 0.8;
float distancefromsensortofloor = 30.0;
int rainrecievedlits;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}

void loop() {
  int timetaken, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  timetaken = pulseIn(echoPin, HIGH);
  dist = (timetaken / 2) * 0.034049 ;
  //Serial.println("Distance in CM: ");

  Serial.println(dist);

  delay(500);

  rainrecievedlits = ((lengthofroof * breadthofroof * runoffcoeff) * (distancefromsensortofloor - dist) * 0.01);
  Serial.println(rainrecievedlits);

}

