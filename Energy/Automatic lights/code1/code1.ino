#define ldr A0//analog pin A0

void setup() {
  Serial.begin(9600);
  pinMode(ldr,INPUT);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
 int reading=analogRead(ldr);//analog reading has the range 0-1023
 Serial.println(reading);
}
