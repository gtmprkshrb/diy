#define relay 8//digital pin 8
#define ldr A0//analog pin A0

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(relay,LOW);//off by default
  pinMode(ldr,INPUT);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
 reading=analogRead(ldr);//analog reading has the range 0-1023
 Serial.println(reading);
 if(reading<=700)//setting a threshold value that can be changed after testing 
 {   
  digitalWrite(relay, HIGH);   //on
  delay(900000);                       // wait for fifteen minutes
}
else
{
  digitalWrite(relay, LOW);    // off
}
}
