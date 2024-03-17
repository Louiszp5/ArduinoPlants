#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// -- Setup Display --
// OLED display TWI address
#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(-1);
#if (SSD1306_LCDHEIGHT != 64 || SSD1306_LCDWIDTH != 128) 
#error("Please redifine dimensions to work with your LCD screen")
#endif

// Define Digital Pins 
const int REED_PIN = 2;


void setup() {
  // set up Serial Debugging
  Serial.begin(9600);
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

  // Set up PINs 
  // PULLUP -> 'HIGH' = OFF, 'LOW' = ON
  pinMode(REED_PIN, INPUT_PULLUP); 
}

void displayText(String text) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  int cursorHeight = 0;
  
  for (int i=0; i < text.length(); i++) {
    if (i >= 160) break;
    if (i!=0 & i%20 == 0) { 
      cursorHeight += 8;
      display.setCursor(0, cursorHeight);
    }
    display.print(text[i]);
  } // Now update the display
  display.display();
}

void loop() {
  int proximity = digitalRead(REED_PIN);
  if (proximity == LOW) {
    displayText("Reed Switch Active    <(^_^)>");
  } else {
    displayText("Reed Switch OFF       \\(°^°)/");
  }

  delay(1000);

  
//  String Socrates = "The unexamined life is not worth living.";
//  displayText(Socrates);  
//  delay(5000);
//
//  String words = "To be or not to be, that is the question";
//  displayText(words);
//  delay(5000);

}
