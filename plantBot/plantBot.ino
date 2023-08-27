// A simple Water pump and LED light controller for indoor plants
// Version 1.5, Last Updated Jul 10 2023
// Created by Karl Poulson

// ----- CONSTANTS -----
const int min_dryness = 300; // the higher the number, the dryer it is.
const int pumpPin = 12;
const int lightPin = 13;
const int soilSensor = A0;
const int saucerLEDPin = 11;
const int seedlingLED = 10;

// ----- TIMERS -----
const int water_time_sec = 20;
const int LED_on_time_hrs = 14;
const int LED_off_time_hrs = 10;

// ----- SETUP ----- 
void setup() {
  // initialize the pins
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  pinMode(lightPin, OUTPUT);
  pinMode(saucerLEDPin, OUTPUT);
  pinMode(seedlingLED, OUTPUT);
  pinMode(soilSensor, INPUT);
  digitalWrite(pumpPin, HIGH);
  digitalWrite(lightPin, HIGH);
  digitalWrite(saucerLEDPin, HIGH);
  digitalWrite(seedlingLED, HIGH);
  delay(seconds(1));
}

// ----- HELPER FUNCTIONS -----
// returns hours converted to ms
// 86400000ms in 24 hours or 3600000ms in an hour
long hours(int milliseconds) {
  long hrs_in_ms = milliseconds * 3600000;
  Serial.println("LED time in ms: " + String(hrs_in_ms));
  return hrs_in_ms;
}

long seconds(int milliseconds) {
  // convert ms to seconds (expressed in ms)
  long ms_in_sec = milliseconds * 1000;
  Serial.println("Watering time in ms: " + String(ms_in_sec));
  return ms_in_sec;
}

// ----- FUNCTIONS -----
void waterPlants() {
  // Activates the water pump when soil is dry
  // read current moisture
  // LOW = on, HIGH = off
  int drynessLevel = analogRead(soilSensor);
  String strDrynessLevel = String(drynessLevel);
  Serial.println("Mositure Level at: " + strDrynessLevel);
  Serial.println("If dryness level (" + String(drynessLevel) + ") is larger than (" + String(min_dryness) + ") Then water plants.");
  while (drynessLevel > min_dryness) {
      Serial.println("Watering starts now. Moisture is " + String(drynessLevel));
      digitalWrite(pumpPin, LOW);
      delay(seconds(water_time_sec));
      digitalWrite(pumpPin, HIGH);
      Serial.println("Done watering.");
      delay(seconds(20));
      drynessLevel = analogRead(soilSensor);
    }
    Serial.println("Moisture is adequate. No watering needed ");
}

void turnLightsOn() {      
  // Activates the switches to turn on the LEDs.
  // LOW = on, HIGH = off    

  // Turn LEDs on
  digitalWrite(lightPin, LOW);
  digitalWrite(saucerLEDPin, LOW);
  digitalWrite(seedlingLED, LOW);
  delay(hours(LED_on_time_hrs)); 

  // Turn LEDs off
  digitalWrite(lightPin, HIGH);
  digitalWrite(saucerLEDPin, HIGH);
  digitalWrite(seedlingLED, HIGH);
  delay(hours(LED_off_time_hrs));     
}

// ----- MAIN LOOP -----
void loop() {
  waterPlants();
  turnLightsOn();
}
