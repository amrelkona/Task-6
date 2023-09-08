#include <Wire.h>

const int MPU6050_ADDRESS = 0x68; // I2C address of the MPU6050

void setup() {
  Wire.begin(); // Initialize I2C communication
  Serial.begin(9600); // Initialize serial communication

  // Configure DLPF to a recommended cutoff frequency of 42Hz
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x1A); // CONFIG register address
  Wire.write(0x03); // Set DLPF setting to 42Hz
  Wire.endTransmission();
}

void loop() {
  // Read the yaw angle from the sensor
  int16_t rawYaw = readSensorValue(0x47); // Register address for yaw angle data
  float yawAngle = rawYaw / 65.5; // Convert raw value to degrees per second

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

