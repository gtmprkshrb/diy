#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int count1, count2 ,count3, count4 ,count5 =0;
void setup()
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Reading!!!...");
  Serial.println();
  

}
void loop()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("HI :");
  String content = "";
  byte letter;
 
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0 " : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Welcome : ");
  content.toUpperCase();
  if (content.substring(1) == "7B EB EE 66") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Sairam");
    Serial.println();
    count1++;
    Serial.print(count1);
    delay(3000);
  }
  if (content.substring(1) == "BB 71 FE 66")
  {
    Serial.println("Gautam");
    Serial.println();
    count2++;
    Serial.print(count2);
    delay(3000);
  }
  else if (content.substring(1) == "30 EF 1C 33")
  {
    Serial.println("Rizwan");
    Serial.println();
    count3++;
    Serial.print(count3);
    delay(3000);
  }

   else if (content.substring(1) == "22 B7 27 95")
  {
    Serial.println("RUTUJA");
    Serial.println();
    count4++;
    Serial.print(count4);
    delay(3000);
  }
   else if (content.substring(1) == "F2 5C 60 6D")
  {
    Serial.println("Maria");
    Serial.println();
    count5++;
    Serial.print(count5);
    delay(3000);
  }
  else   {
    Serial.println(" Access denied");
    delay(3000);
  }
}
  
