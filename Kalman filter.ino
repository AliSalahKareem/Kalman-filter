const int sensorPin = A0;  // Myoware 2.0 sensor is connected to analog pin A0
float Q = 0.1;  // Process noise covariance
float R = 0.1;  // Measurement noise covariance
float P = 1;  // Estimate error covariance
float K;  // Kalman gain
float x = 0;  // Estimated value
float previousX = 0;  // Previous estimated value
float sensorValue;  // Raw sensor value

void setup() {
  // Put your setup code here, to run once:
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  // Put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);  // Read the raw sensor value
  previousX = x;  // Update the previous estimate
  P = P + Q;  // Update the estimate error covariance
  K = P / (P + R);  // Calculate the Kalman gain
  x = previousX + K * (sensorValue - previousX);  // Calculate the new estimate
  P = (1 - K) * P;  // Update the estimate error covariance
  Serial.println(x);  // Debugging: print the filtered value to the serial monitor
  delay(10);  // Delay for a short time to allow the serial monitor to keep up
}