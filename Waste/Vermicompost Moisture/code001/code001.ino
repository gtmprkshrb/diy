//soil moisture sensor
#define soilMoisture1 A0 //connect analog pin of soil moisture sensor1 to A0 of Arduino                   
#define soilMoisture2 A1 //connect analog pin of soil moisture sensor2 to A1 of Arduino                   
//calibration
//maximum value detected(dry) 1025
//minimum value detected(wet) 10
//percentage of moisture= 100-(detected/maximum*100)
//100/maximum=100/1025=0.0975

unsigned long moisture1,moisture2, moisture;
float percentage;

void setup() {
  // put your setup code here, to run once:
   // Initialize a serial connection for reporting values to the host
  Serial.begin(115200);
  pinMode(soilMoisture1,INPUT);
  pinMode(soilMoisture2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   moisture1=analogRead(soilMoisture1);//read input from pin A0(soilMoisture)
   moisture2=analogRead(soilMoisture2);//read input from pin A1(soilMoisture)
   moisture=(moisture1+moisture2)/2;//taking the average for a more reliable result
   Serial.print("Moisture: ");
   Serial.print(moisture);
   Serial.print("\t");
   percentage=100-(moisture*0.0975);//express as a percentage
   Serial.print("Percentage: ");
   Serial.print(percentage);
   Serial.println("%");
   delay(3000);
}
