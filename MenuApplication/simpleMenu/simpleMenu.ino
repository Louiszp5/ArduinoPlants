// Define constants for button pins
const int UP_BUTTON_PIN = 2;
const int DOWN_BUTTON_PIN = 3;
const int SELECT_BUTTON_PIN = 4;
const int BACK_BUTTON_PIN = 5;

// Define constants for button states
const int BUTTON_PRESSED = LOW;
const int BUTTON_NOT_PRESSED = HIGH;

// Define variables to store button states
int upButtonState = BUTTON_NOT_PRESSED;
int downButtonState = BUTTON_NOT_PRESSED;
int selectButtonState = BUTTON_NOT_PRESSED;
int backButtonState = BUTTON_NOT_PRESSED;

void setup() {
  // Set button pins as inputs
  pinMode(UP_BUTTON_PIN, INPUT_PULLUP);
  pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);
  pinMode(SELECT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(BACK_BUTTON_PIN, INPUT_PULLUP);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read button states
  upButtonState = digitalRead(UP_BUTTON_PIN);
  downButtonState = digitalRead(DOWN_BUTTON_PIN);
  selectButtonState = digitalRead(SELECT_BUTTON_PIN);
  backButtonState = digitalRead(BACK_BUTTON_PIN);

  // Check if any button is pressed
  if (upButtonState == BUTTON_PRESSED) {
    Serial.println("Up button pressed");
  }
  if (downButtonState == BUTTON_PRESSED) {
    Serial.println("Down button pressed");
  }
  if (selectButtonState == BUTTON_PRESSED) {
    Serial.println("Select button pressed");
  }
  if (backButtonState == BUTTON_PRESSED) {
    Serial.println("Back button pressed");
  }

  // Delay to debounce buttons
  delay(100);
}
