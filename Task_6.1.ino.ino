#include <Wire.h>

const int MPU6050_ADDRESS = 0x68; // I2C address of the MPU6050

void setup() {
  Wire.begin();
  Serial.begin(9600);
  // Configure DLPF to a recommended cutoff frequency of 42Hz
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x1A); 
  Wire.write(0x03); 
  Wire.endTransmission();
}

void loop() {
  // Read the yaw angle from the sensor
  int16_t rawYaw = readSensorValue(0x47); 
  float yawAngle = rawYaw / 131.0; 
  // Print the yaw angle
  Serial.print("Yaw angle: ");
  Serial.println(yawAngle);

  delay(100);
}

int16_t readSensorValue(byte regAddress) {
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(regAddress);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDRESS, 2);
  byte highByte = Wire.read();
  byte lowByte = Wire.read();
  return (highByte << 8) | lowByte;
}

