#define vibPin 6

int vib = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(vibPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  vib = (vib % 220);
  analogWrite(vibPin, vib++);
  delay(30);
}
