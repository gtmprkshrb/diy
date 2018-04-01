/*This project explains the use of RGB LED */


#define greenpin 12
#define bluepin 13
#define redpin 11
void setup() {
  
pinMode(redpin, OUTPUT);
pinMode(greenpin, OUTPUT);
pinMode(bluepin, OUTPUT);
}

void loop() {
/*All are LOW*/
  digitalWrite(redpin,LOW);
  digitalWrite(greenpin, LOW);
  digitalWrite(bluepin, LOW);
  delay(1000);
  /*Red LED high*/
  digitalWrite(redpin, HIGH);
   digitalWrite(greenpin, LOW);
  digitalWrite(bluepin, LOW);
  delay(2000);
 /*Green LED high*/
  digitalWrite(greenpin, HIGH);
  digitalWrite(bluepin, LOW);
  digitalWrite(redpin, LOW);
  delay(2000);
  /*Blue LED high*/
  digitalWrite(greenpin, LOW);
  digitalWrite(bluepin, HIGH);
  digitalWrite(redpin, LOW);
  delay(2000);
 
}
