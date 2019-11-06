// constants won't change. They're used here to set pin numbers:
const int button1Pin = 2;     // the number of the pushbutton 1 pin
const int vib1Pin = 5;      // the number of the vib 1 pin

const int button2Pin = 7;     // the number of the pushbutton pin 2
const int vib2Pin = 6;       // the number of the vib 2 pin
// variables will change:
int button1State = 0;         // variable for reading the pushbutton1 status
int button2State = 0;         // variable for reading the pushbutton2 status

void setup() {
  // initialize the LED pin as an output:
  pinMode(vib1Pin, OUTPUT);
  pinMode(vib2Pin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (button1State == HIGH) {
    // vibrate motor
    analogWrite( vib1Pin , 153 );
  } else {
    // turn  off motor
    analogWrite( vib1Pin , 0 );
  }

  if (button2State == HIGH) {
    // vibrate motor
    analogWrite( vib2Pin , 153 );
  } else {
    // turn  off motor
    analogWrite( vib2Pin , 0 );
  }
}
