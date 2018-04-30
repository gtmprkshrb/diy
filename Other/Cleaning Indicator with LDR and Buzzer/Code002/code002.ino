//This code exaplins the working of LDR sensor.
//Shows light intensity data on Serial monitor
//Based on values of light intensity, we can identify easily the desk/window/door has to be cleaned or not

#define ldr A0//analog pin A0
#define buzzer 13

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  int reading = analogRead(ldr); //analog reading has the range 0-1023
  Serial.println(reading);
  if (reading < 400) {
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
  }
}
