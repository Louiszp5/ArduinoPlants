// A simple Water pump and LED light controller that enable indoor plant growth
// Version 1.1
// Created by Karl Poulson

// constants
const int dry = 300; // the higher the number, the dryer it is.
const int pumpPin = 12;
const int lightPin = 13;
const int soilSensor = A4;
const int saucerLEDPin = 11;


void setup() {
  // initialize the pins with pull down resistors
  pinMode(pumpPin, OUTPUT);
  pinMode(lightPin, OUTPUT);
  pinMode(saucerLEDPin, OUTPUT);
  pinMode(soilSensor, INPUT);
  Serial.begin(9600);
  digitalWrite(pumpPin, HIGH);
  digitalWrite(lightPin, HIGH);
  digitalWrite(saucerLEDPin, HIGH);
  delay(5000);
}

void waterPlants() {
  // read current moisture
  int moistureLevel = analogRead(soilSensor);
  Serial.println("Mositure Level at: " + String(moistureLevel));
  
  if (dry <= moistureLevel) 
    {
      Serial.println("Watering starts now. Moisture is " + String(moistureLevel));
      digitalWrite(pumpPin, LOW);
      delay(100000);
      digitalWrite(pumpPin, HIGH);
      Serial.println("Done watering.");
      // delay, let water seep in.
      delay(10000);
      waterPlants();
    }
  else {
    Serial.println("Moisture is adequate. No watering needed " + String(moistureLevel));
  }
}

// returns hours converted to ms
// 86400000ms in 24 hours or 3600000ms in an hour
int hours_to_ms(int hours) {
  int LED_time = hours * 3600000;
  return LED_time;
}

// Activates the switches to turn on the LEDs
void turnLightsOn() {   
  // turn LEDs on 
  digitalWrite(lightPin, LOW);
  digitalWrite(saucerLEDPin, LOW);
  delay(hours_to_ms(16));    
  // turn LEDs off        
  digitalWrite(lightPin, HIGH);
  digitalWrite(saucerLEDPin, HIGH);
  delay(hours_to_ms(8));     
}

void loop() {
  waterPlants();
  turnLightsOn();
}
