#include <EEPROM.h>     // We are going to read and write PICC's UIDs from/to EEPROM
#include <SPI.h>        // RC522 Module uses SPI protocol
#include <MFRC522.h>	// Library for Mifare RC522 Devices

#define SS_PIN 10
#define RST_PIN 9

byte storedCard[4] = {163, 142, 192, 2};		// Stores an ID read from EEPROM
byte readCard[4];		// Stores scanned ID read from RFID Module
byte masterCard[4];	
MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance.


void setup() {

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);

  //Protocol Configuration
  Serial.begin(9600);	 // Initialize serial communications with PC
  SPI.begin();           // MFRC522 Hardware uses SPI protocol
  mfrc522.PCD_Init();    // Initialize MFRC522 Hardware
  
  //If you set Antenna Gain to Max it will increase reading distance
  mfrc522.PCD_SetAntennaGain(mfrc522.RxGain_max);
}


///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop () {
  if ( ! mfrc522.PICC_IsNewCardPresent()) { //If a new PICC placed to RFID reader continue
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {   //Since a PICC placed get Serial and continue
    return;
  }
  for (int i = 0; i < 4; i++) {
    readCard[i] = mfrc522.uid.uidByte[i];
  }
  mfrc522.PICC_HaltA();
  
  if (checkTwo(readCard, storedCard)) {
    unlock();
    delay(10000);
    lock();
    software_Reset();
  }
}

boolean checkTwo ( byte a[], byte b[] ) {
  boolean match;
  if ( a[0] != NULL ) 			// Make sure there is something in the array first
    match = true; 			// Assume they match at first
  for ( int k = 0; k < 4; k++ ) { 	// Loop 4 times
    if ( a[k] != b[k] ) 		// IF a != b then set match = false, one fails, all fail
      match = false;
  }
  return match;
}

void lock() {
  Serial.println("Lock");
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  delay(100);
  digitalWrite(9, HIGH);
  digitalWrite(6, HIGH);
}

void unlock() {
  Serial.println("Unlock");
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(100);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
}

void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
asm volatile ("  jmp 0");  
}  
