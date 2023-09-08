const int encoderPinA = 2;  // Connect the A channel to digital pin 2
const int encoderPinB = 3;  // Connect the B channel to digital pin 3

volatile int count = 0;     // Counter variable, declared as volatile for interrupt handling

void setup() {
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), handleEncoder, CHANGE);

  Serial.begin(9600);
}

void loop() {
  // Your main code here
  // You can use the count variable to do further calculations or display the count value
}

void handleEncoder() {
  if (digitalRead(encoderPinA) == digitalRead(encoderPinB)) {
    count++;
  } else {
    count--;
  }
}

