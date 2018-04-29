//Student idea of Testing Two wheeler Vehicular Emission
//and periodically sends message to user
//GSM, LCD, MQ7

#include <Adafruit_FONA.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x3F); // address of LCD, change to 0x27 if needed.

#define FONA_RX 5
#define FONA_TX 6

//#define FONA_RST 4
SoftwareSerial fona (FONA_TX, FONA_RX);
char replybuffer[255];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  fona.begin(9600);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home();
  lcd.print("Hello ");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  int val;
  val = analogRead(0);
  Serial.println(val, DEC);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("CO Level");
  lcd.setCursor(0, 1);
  lcd.print(val, DEC);
  if (val > 200) {
    lcd. setCursor(4, 2);
    lcd.print("Not Safe");
    fona.print("AT+CMGF=1\r");
    delay(1000);
    fona.print("AT+CMGS=\"+91xxxxxxxxx\"\r");//enter your number

    delay(1000);
    fona.print("Please do Emission Test!!!");
    fona.print("\r");

    delay(1000);
    fona.println((char)26);
    fona.println();

    delay(10000);
  }
  else {
    lcd. setCursor(4, 2);
    lcd.print("safe");
    fona.print("AT+CMGF=1\r");
    delay(1000);
    fona.print("AT+CMGS=\"+91xxxxxxxxxx\"\r");//enter your number

    delay(1000);
    fona.print("you are an active citizen!!!");
    fona.print("\r");

    delay(1000);
    fona.println((char)26);
    fona.println();

    delay(10000);
  }
}





