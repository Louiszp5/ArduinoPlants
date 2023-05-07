const int dry = 300; // the higher the number, the dryer it is.

const int pumpPin = 12;
const int lightPin = 13;
const int soilSensor = A4;
const int saucerLEDPin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(pumpPin, OUTPUT);
  pinMode(lightPin, OUTPUT);
  pinMode(saucerLEDPin, OUTPUT);
  pinMode(soilSensor, INPUT);
  Serial.begin(9600);
  digitalWrite(pumpPin, HIGH);  //enable pulldown resistor?
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

void turnLightsOn() {         // 8640000 ms in 24 hours or 352500 ms in an hour and 28800000 ms in 8 hours
  digitalWrite(lightPin, LOW); // Turns lights off, then on.
  digitalWrite(saucerLEDPin, LOW);
  delay(43200000);            // 12 hours off, 12 hours on. 
  digitalWrite(lightPin, HIGH);
  digitalWrite(saucerLEDPin, HIGH);
  delay(43200000);           // Turn LEDs on for 8 hours
}

void loop() {
  waterPlants();
  turnLightsOn();
}
