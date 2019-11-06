#include <math.h>
// constants won't change. They're used here to set pin numbers:
#define f3Sense A1     // the number of the pushbutton 1 pin
#define f3Vib 5      // the number of the vib 1 pin

#define f4Sense A0     // the number of the pushbutton pin
#define f4Vib 6     // the number of the vib 2 pin
// variables will change:
float f3Pressure = 0;         // variable for reading the FSR status
float f4Pressure = 0;         // variable for reading the FSR status
float f3Force = 0;
float f4Force = 0;

void setup(){
  // initialize the LED pin as an output:
  pinMode(f3Vib, OUTPUT);
  pinMode(f4Vib, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(f3Sense, INPUT);
  pinMode(f4Sense, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
 float f3output = sense(f3Sense,f3Vib);
 float f4output = sense(f4Sense,f4Vib);

  analogWrite(f3Vib, f3output);
  analogWrite(f4Vib, f4output);

  Serial.print(f3output);
  Serial.print(",");
  Serial.print(analogRead(f3Sense));
  Serial.print(",");

  Serial.print(f4output);
  Serial.print(",");
  Serial.print(analogRead(f4Sense));
  Serial.print(",");
  Serial.println(153);
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

float sense(int pressurePin, int vibrationPin) {
  float pressure = analogRead(pressurePin);
  Serial.print(exp(pressure));
  return (pressure*153)/1000; 
}
