#include <math.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

// constants won’t change. They’re used here to set pin numbers:
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

//int vibPin = 3;
//int piezoPin = 10;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int servoAngle = 0;   // servo position in degrees
void setup(){
  // PRESSURE SENSE INITIATION
  pinMode(f1Sense, INPUT);
  pinMode(f2Sense, INPUT);
  pinMode(f3Sense, INPUT);
  pinMode(f4Sense, INPUT);
  pinMode(f5Sense, INPUT);
  //pinMode(vibPin, OUTPUT);
  //pinMode(piezoPin, OUTPUT);
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
  // TEMP SENSE INITIATION
  mlx.begin();
  Serial.begin(9600);
}
void pressure(){
  // VIBRATION OUTPUT
  // float f3output = sense(f3Sense,f3Vib);
  // SERVO OUTPUT
  float f1servoOutput = servoSense(f1Sense,servo1Pin);
  float f2servoOutput = servoSense(f2Sense,servo2Pin);
  float f3servoOutput = servoSense(f3Sense,servo3Pin);
  float f4servoOutput = servoSense(f4Sense,servo4Pin);
  float f5servoOutput = servoSense(f5Sense,servo5Pin);
  
  //  Serial.print(pressure1);
  //  Serial.print(“,”);
  //  Serial.print(pressure2);
  //  Serial.print(“,”);
  //  Serial.print(pressure3);
  //  Serial.print(“,”);
  //  Serial.print(pressure4);
  //  Serial.print(“,”);
  //  Serial.println(pressure5);
  servo1.write(f1servoOutput);
  servo2.write(f2servoOutput);
  servo3.write(f3servoOutput);
  servo4.write(f4servoOutput);
  servo5.write(f5servoOutput);
  //  Serial.print(f3servoOutput);
  //  Serial.print(“,”);
  //  Serial.print(analogRead(f3Sense));
  //  Serial.print(“,”);
  //
  //  Serial.print(f4servoOutput);
  //  Serial.print(“,”);
  //  Serial.print(analogRead(f4Sense));
  //  Serial.print(“,”);
  //  Serial.println(153);
}

//float sense(int pressurePin, int vibrationPin) {
  //float pressure = analogRead(pressurePin);
  //Serial.print(exp(pressure));
  //return (pressure*153)/1000;
//}

//void temperature(){
//  //Serial.print(mlx.readObjectTempC());
//  //Serial.println();
//  float tempSample = mlx.readObjectTempC();
//  Serial.println(tempSample);
//  
//  if (tempSample > 60){
//    //Serial.print(“Temp more than 60");
//    analogWrite(piezoPin, 255);
//    analogWrite(vibPin, 153);
//    delay(200);
//    analogWrite(piezoPin, 0);
//  } else if (tempSample > 30) {
//    // Serial.println(“Temp more than 30”);
//    // We take 60 degrees to be our max temp, because after this point, the vib motor will pulse
//    // Minusing 30 degrees will make our range between 0 and 30. Dividing this by 30 will normalise
//    // the range. Multiplying this normalised value by 153(the max vib voltage) will give the appropriate
//    // vibration output
//    analogWrite(piezoPin, 0);
//    float normalizedTemp = ((tempSample - 30) / 30);
//    analogWrite(vibPin, int(normalizedTemp * 153));
//  } else {
//    analogWrite(vibPin,0);
//    analogWrite(piezoPin, 0);
//  }
//}

float servoSense(int pressurePin, int servoPin) {
  float pressure = analogRead(pressurePin);
  Serial.println(pressure);
  //Serial.print(“New test”);
  //Serial.print(60 - exp((pressure * 5) / 1000));
  //Serial.print(“\n”);
  if (pressure <= 400) {
    pressure = 0.6 * pressure;
  } else if (pressure <= 800) {
    pressure = ((pressure - 400) * 1.2) + 240;
  } else {
    pressure = ((pressure - 800) * 0.6) + 700;
  }
  
  return (60 - ((pressure/1000)*60));
}

void loop() {
  pressure();
  //temperature();
}
