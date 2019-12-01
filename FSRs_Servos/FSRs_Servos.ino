#include <math.h>
#include <Servo.h>

// constants won't change. They're used here to set pin numbers:

#define f1Sense A0
#define f2Sense A1
#define f3Sense A2    
#define f4Sense A3  
#define f5Sense A4

//// variables will change:
//float f3Pressure = 0;         // variable for reading the FSR status
//float f4Pressure = 0;         // variable for reading the FSR status
//float f3Force = 0;
//float f4Force = 0;

int servo1Pin = 5; // f1
int servo2Pin = 6; // f2
int servo3Pin = 9; // f3
int servo4Pin = 10; // f4
int servo5Pin = 11; // f5
 
Servo servo1;  
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
 
int servoAngle = 0;   // servo position in degrees


void setup(){


  // initialize the pushbutton pin as an input:
  pinMode(f1Sense, INPUT);
  pinMode(f2Sense, INPUT);
  pinMode(f3Sense, INPUT);
  pinMode(f4Sense, INPUT);
  pinMode(f5Sense, INPUT);

  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);
  servo5.attach(servo5Pin);
  
  servo1.write(60);
  servo2.write(60);
  servo3.write(60);
  servo4.write(60);
  servo5.write(60);

  Serial.begin(9600);
}

void loop() {
// VIBRATION OUTPUT
// float f3output = sense(f3Sense,f3Vib);
// float f4output = sense(f4Sense,f4Vib);

// SERVO OUTPUT
  float f1servoOutput = servoSense(f1Sense,servo1Pin);
  float f2servoOutput = servoSense(f2Sense,servo2Pin);
  float f3servoOutput = servoSense(f3Sense,servo3Pin);
  float f4servoOutput = servoSense(f4Sense,servo4Pin);
  float f5servoOutput = servoSense(f5Sense,servo5Pin);

  float pressure1 = analogRead(f1Sense);
  float pressure2 = analogRead(f2Sense);
  float pressure3 = analogRead(f3Sense);
  float pressure4 = analogRead(f4Sense);
  float pressure5 = analogRead(f5Sense);

  Serial.print(pressure1);
  Serial.print(",");
  Serial.print(pressure2);
  Serial.print(",");
  Serial.print(pressure3);
  Serial.print(",");
  Serial.print(pressure4);
  Serial.print(",");
  Serial.println(pressure5);
        
  

  servo1.write(f1servoOutput);
  servo2.write(f2servoOutput);
  servo3.write(f3servoOutput);
  servo4.write(f4servoOutput);
  servo5.write(f5servoOutput);


//  Serial.print(f3servoOutput);
//  Serial.print(",");
//  Serial.print(analogRead(f3Sense));
//  Serial.print(",");
//
//  Serial.print(f4servoOutput);
//  Serial.print(",");
//  Serial.print(analogRead(f4Sense));
//  Serial.print(",");
//  Serial.println(153);
  }



  

//  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//  if (button1State == HIGH) {
//    // vibrate motor
//    analogWrite( vib1Pin , 153 );
//  } else {
//    // turn  off motor
//    analogWrite( vib1Pin , 0 );
//  }
//
//  if (button2State == HIGH) {
//    // vibrate motor
//    analogWrite( vib2Pin , 153 );
//  } else {
//    // turn  off motor
//    analogWrite( vib2Pin , 0 );
//  }
//}

//float sense(int pressurePin, int vibrationPin) {
//  float pressure = analogRead(pressurePin);
//  Serial.print(exp(pressure));
//  return (pressure*153)/1000; 
//}

float servoSense(int pressurePin, int servoPin) {
  float pressure = analogRead(pressurePin);
  //Serial.print("New test");
  //Serial.print(60 - exp((pressure * 5) / 1000));
  //Serial.print("\n");
  return (60 - ((pressure/1000)*60));
}
