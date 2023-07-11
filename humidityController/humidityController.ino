// V 1.0
// Simple Humidity and LED control
// Created by Karl Poulson


const int fogPump = 5;
const int airPump = 6;
const int LEDs    = 7;
const int delayTime = 5000;

void setup(){
  pinMode(airPump, OUTPUT);
  pinMode(fogPump, OUTPUT);
  pinMode(LEDs,    OUTPUT);
}

void loop(){ // 30 min on, hour and a half off
  digitalWrite(airPump, HIGH);  // 30 min fully on
  digitalWrite(fogPump, HIGH);
  digitalWrite(LEDs,    HIGH);
  delay(1800000);
  
  digitalWrite(airPump, LOW);   // 1.5 hours off
  digitalWrite(fogPump, LOW);
  digitalWrite(LEDs,    LOW);
  delay(5400000);


}
