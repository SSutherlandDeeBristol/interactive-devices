#include <Servo.h> 

#define fsrPin0 A0
#define fsrPin1 A1
#define fsrPin2 A2
#define fsrPin3 A3

#define piezoPin 9

#define servoPin 3

int fsrReadings[4];
int averageReading;

Servo servo1;

void setup() {
  pinMode(fsrPin0, INPUT);
  pinMode(fsrPin1, INPUT);
  pinMode(fsrPin2, INPUT);
  pinMode(fsrPin3, INPUT);
  pinMode(piezoPin, OUTPUT);

  servo1.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  fsrReadings[0] = analogRead(fsrPin0);
  fsrReadings[1] = analogRead(fsrPin1);
  fsrReadings[2] = analogRead(fsrPin2);
  fsrReadings[3] = analogRead(fsrPin3);

  averageReading = 0;
  
  for (int i = 0; i < 4; i++) {
    // Print the fsrreading in the serial monitor:
    // Print the string "Analog reading = ".
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(" reading = ");
    Serial.print(fsrReadings[i]);
    averageReading += fsrReadings[i];
  }

  averageReading /= 4;
  
  // We can set some threshholds to display how much pressure is roughly applied:
  if (averageReading < 10) {
    Serial.println(" - No pressure");
  } else if (averageReading < 200) {
    Serial.println(" - Light touch");
  } else if (averageReading < 500) {
    Serial.println(" - Light squeeze");
  } else if (averageReading < 800) {
    Serial.println(" - Medium squeeze");
  } else {
    Serial.println(" - Big squeeze");
  }

  tone(piezoPin, averageReading);

  if (averageReading < 1e-6 || averageReading > 359)
    averageReading = 0;

  servo1.write(averageReading * 4 / 10);
  
  delay(100); //Delay 300 ms.
}
