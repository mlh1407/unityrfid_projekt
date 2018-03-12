constexpr uint8_t RST_PIN = 9;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = 10;     // Configurable, see typical pin layout above
#include <SPI.h>
#include <MFRC522.h>
#include <Keyboard.h>
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.
MFRC522::MIFARE_Key key;
String content= "";

//TTTTTT






void setup() {
  Serial.begin(9600);  // Initialize serial communications with the PC
  while (!Serial);     // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();         // Init SPI bus
  mfrc522.PCD_Init();  // Init MFRC522 card
  Keyboard.begin();
  Serial.println(F("Sæt dit kort eller brik på kort/brik læseren for at få information"));
  
  // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  
}











void loop() {
  content= "";
  // Look for new cards, and select one if present
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  
  // Now a card is selected. The UID and SAK is in mfrc522.uid.
  
  // Dump UID
  Serial.println("#----------------------#");
  Serial.print(F("UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
     
  } 
  Serial.println();

  content.toUpperCase();
  
  if (content.substring(1) == "49 9E AE D5") //change here the UID of the card/cards that you want to give access
  { 
    Serial.println("Dette er et kort");
    
  }
  
  else if (content.substring(1) == "A4 04 75 2E") //change here the UID of the card/cards that you want to give access
  { 
    Serial.println("Dette er en brik");
    
  }
  
  else {
    Serial.println("*Ukendt UID*");
  }
  
  Serial.print("#----------------------#");
  Serial.println();

  Keyboard.println(content.substring(1));

 
  
  
 
  
  
  delay(500);
}
