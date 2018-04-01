// intelligent trash can
int sensor_pin = A0; // select the input pin for the potentiometer

#include <Servo.h>
Servo servoDry; // Define our Servo
Servo servoWet; // Define our Servo


void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  servoDry.attach(9); // servo on digital pin 9
  servoWet.attach(10); // servo on digital pin 10

}
void loop() {
  int value = analogRead(sensor_pin);
  //value = value / 10;
  Serial.println(value);
  //

  if (value >= 1000)
  {
    servoDry.write(0);  // 10 pin
    servoWet.write(0);
    delay(1000);          // Wait 1 second
  }
  else if (value < 1000 && value > 700)
  {
    servoDry.write(270);   // 6 pin
    //servoWet.write(0);
    delay(5000);          // Wait 1 second
  }
  else if (value <= 700) {
    servoWet.write(270);
    delay(10000);
  }
}


