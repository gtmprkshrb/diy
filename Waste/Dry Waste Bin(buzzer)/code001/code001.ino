#define soilMoisture A1 //connect analog pin of soil moisture sensor to A0 of Arduino                   

unsigned long moisture;
float percentage;

void setup() {
  Serial.begin(115200);
  pinMode(soilMoisture,INPUT);
}

void loop() {
   moisture=analogRead(soilMoisture);//read input from pin A0(soilMoisture)
   Serial.print("Moisture: ");
   Serial.print(moisture);
   delay(3000);
}
