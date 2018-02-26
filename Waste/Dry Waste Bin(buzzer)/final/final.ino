//soil moisture sensor
#define soilMoisture A0 //connect analog pin of soil moisture sensor to A0 of Arduino                   
//calibration
//maximum value detected(dry) 1025
//minimum value detected(wet) 10
//percentage of moisture= 100-(detected/maximum*100)
//100/maximum=100/1025=0.0975

unsigned long moisture;
float percentage;

//buzzer
#define buzzer 2//connect VCC of buzzer to digital data pin 2

void setup() {
  // put your setup code here, to run once:
   // Initialize a serial connection for reporting values to the host
  Serial.begin(115200);
  pinMode(soilMoisture,INPUT);
  pinMode(buzzer,2);
  digitalWrite(buzzer,LOW);//by default buzzer is off
}

void loop() {
  // put your main code here, to run repeatedly:
   moisture=analogRead(soilMoisture);//read input from pin A0(soilMoisture)
   Serial.print("Moisture: ");
   Serial.print(moisture);
   Serial.print("\t");
   percentage=100-(moisture*0.0975);//express as a percentage
   Serial.print("Percentage: ");
   Serial.print(percentage);
   Serial.println("%");
   if(percentage>=20)
   {
    digitalWrite(buzzer,HIGH);//buzzer beeps indicating wet waste in dry waste
    delay(5000);//delay of five seconds
    digitalWrite(buzzer,LOW);//buzzer stops beeping after five seconds
   }
}
