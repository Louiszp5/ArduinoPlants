// V 1.0

// Simple Humidity and LED control


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

 //delay(21600000);             // on for 6 hours
// 86400000 ms in 24 hours
// 3600000  ms in 1  hour
// 1800000  ms in 30 minutes

// Test Time:
// 6 hours ON, 18 hours OFF
// 6  hours: 21600000
// 18 hours: 64800000
