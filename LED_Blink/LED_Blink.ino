#include <
#include <SPI.h>


// Define constants for LED pins
const int RED_PIN = 2;
const int YELLOW_PIN = 3;
const int GREEN_PIN = 4;
bool garageClose = true;

// Define constants for RFID
#define SDA_PIN 10
#define SCK_PIN 13
#define MOSI_PIN 11
#define MISO_PIN 12
#define RST_PIN 9

Adafruit_MFRC630 mfrc630(SDA_PIN, SCK_PIN, MOSI_PIN, MISO_PIN, RST_PIN);

void setup() {
  // Set LED pins as outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  Serial.begin(9600);

  // SETUP FOR RFID
  mfrc630.begin();          // Init MFRC630 card
  pinMode(LED_PIN, OUTPUT); // Initialize the LED pin as an output
  Serial.println("Scan a card/tag");
}

void loop() {
  // Serial.println("No RFID DETECTED");
  if (garageClose == true) {
    // Serial.println("Garage is closed");
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
  } else {
    // Serial.println("Garage is open");
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);
    closeGarage();
  }
  delay(1000);

  // Detect if RFID card is present
  if (!mfrc630.poll()) {
    // Turn the LED off
    Serial.println("No new card present");
    digitalWrite(LED_PIN, LOW);
    return;
  }
  Serial.println("CARD DETECTED");
  if (!mfrc630.readPassiveTargetID()) {
    // Turn the LED off
    digitalWrite(LED_PIN, LOW);
    return;
  }
  else {
    printUUID();
  }
}

void printUUID() {
  Serial.print("UID tag :");
  for (byte i = 0; i < mfrc630.uid.size; i++) {
    Serial.print(mfrc630.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc630.uid.uidByte[i], HEX);
  }
  Serial.println();
}

void openGarage() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(3000); // 3 seconds delay
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  garageClose = false;
}

void closeGarage() {
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(3000); // 3 seconds delay
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);
  garageClose = true;
}
