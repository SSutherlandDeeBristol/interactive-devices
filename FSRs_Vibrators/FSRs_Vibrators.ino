#include <math.h>


#define f3Sense A1    // the number of the fsr 1 pin
#define f3Vib 5       // the number of the vib 1 pin

#define f4Sense A0    // the number of the fsr 2 pin
#define f4Vib 6       // the number of the vib 2 pin


float f3Pressure = 0; // variable for reading the FSR status
float f4Pressure = 0; // variable for reading the FSR status
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
  const float f3output = sense(f3Sense,f3Vib);
  const float f4output = sense(f4Sense,f4Vib);

  analogWrite(f3Vib, f3output);
  analogWrite(f4Vib, f4output);

  Serial.print("f3: ");
  Serial.print(f3output);
  Serial.print(",");
  Serial.print("f3output: ");
  Serial.print(f3output);
  Serial.print(",");
  Serial.print("f4: ");
  Serial.print(f4output);
  Serial.print(",");
  Serial.print("f4output: ");
  Serial.print(f4output);
  Serial.println();
}

float sense(const int& pressurePin, const int& vibrationPin) {
  const float pressure = analogRead(pressurePin);
  return exp(pressure/200); 
}
