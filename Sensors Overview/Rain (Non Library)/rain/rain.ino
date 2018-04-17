const int VAL_PROBE = 2; // Analog pin 0
 
void setup() {
    Serial.begin(9600);
    pinMode(VAL_PROBE, INPUT);
}
 
void loop() {
  rainfall();
}

void rainfall(){
    int rain = analogRead(VAL_PROBE);
    Serial.println(rain);
}

