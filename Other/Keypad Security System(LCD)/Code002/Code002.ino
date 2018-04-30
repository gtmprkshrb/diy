//Idea of Intruder Detection for Saftey in Homes with
//Keypad , LCD and Buzzer.

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27); // address of LCD, change to 0x3F if needed
#include <Keypad.h>

#define Password_Length 8

int buzzer = 13;

char Data[Password_Length];
char Master[Password_Length] = "123A456";//change the password if needed
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);



void setup() {
  lcd.home();
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home();
  lcd.print("Hello ");
  delay(1000);
  lcd.clear();
  pinMode(buzzer, OUTPUT);
}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  customKey = customKeypad.getKey();
  if (customKey) {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  if (data_count == Password_Length - 1) {
    lcd.clear();

    if (!strcmp(Data, Master)) {
      lcd.print("Correct");
      digitalWrite(signalPin, LOW);
      delay(5000);
      
    }
    else {
      lcd.print("Incorrect");
      digitalWrite(buzzer, HIGH);
      delay(3000);
      digitalWrite(buzzer, LOW);
    }

    lcd.clear();
    clearData();
  }
}

void clearData() {
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
  return;
}

