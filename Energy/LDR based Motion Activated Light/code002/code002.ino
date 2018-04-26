/*This code explains the motion activated light with LDR based
on light intensity values and turns ON/OFF LED bulb/tubelight with
help of One channel Relay, LDR sensor and LED bulb/tubelight*/

#define relay 3  //digital pin 3
#define ldr A0   //analog pin A0

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(relay,LOW);  //off by default
  pinMode(ldr,INPUT);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
 reading=analogRead(ldr);//analog reading has the range 0-1023
 Serial.println(reading);
 if(reading<=700)       //Change value here after testing 
 {   
  digitalWrite(relay, HIGH);   //Relay ON, LED light OFF
  delay(10000);     //Wait for 10 seconds                 
}
else
{
  digitalWrite(relay, LOW);    // Relay OFF, LED light ON
}
}
