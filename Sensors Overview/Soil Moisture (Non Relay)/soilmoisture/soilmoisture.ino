const int VAL_PROBE = 1; // Analog pin 0
 
void setup() {
    Serial.begin(9600);
    pinMode(VAL_PROBE, INPUT);
}
 
void loop() {
  conductivity();
}

void conductivity(){
    int moisture = analogRead(VAL_PROBE);
    Serial.println(moisture);
}

