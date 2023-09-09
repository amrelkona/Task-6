const int encoderPinA = 2;
const int encoderPinB = 3; 

volatile int count = 0;     
void setup() {
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), handleEncoder, CHANGE);

  Serial.begin(9600);
}

void loop() {
  
}

void handleEncoder() {
  if (digitalRead(encoderPinA) == digitalRead(encoderPinB)) {
    count++;
  } else {
    count--;
  }
}

