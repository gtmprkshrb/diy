int trig=8;
int echo=9;
void setup(){
  Serial.begin(4800);
    pinMode(LED_BUILTIN, OUTPUT);

}
void loop(){
  pinMode(trig,OUTPUT);
  long duration, Cm;
  //long microsecondsToCentimeters(float microseconds);
  //long microseconds;
  digitalWrite (trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  pinMode(echo,INPUT);
  duration=pulseIn(echo,HIGH);
  Cm = microsecondsToCentimeters(duration);
  Serial.print("The distance is ");
  Serial.println(Cm);
  if (Cm<15)
  {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); }                      // wait for a second
  else {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  }
}

long microsecondsToCentimeters (long microseconds)
{
   return microseconds /29 /2;
  }
  
  
    
