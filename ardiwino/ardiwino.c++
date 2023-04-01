#include <Servo.h>

int photoresistorPin = A0; // Analog pin for photoresistor
int servoPin = 9; // Digital pin for servo motor

int minAngle = 0; // Minimum angle for the servo
int maxAngle = 180; // Maximum angle for the servo

int threshold = 500; // Photoresistor threshold for switching direction

Servo solarServo; // Initialize the servo

void setup() {
  solarServo.attach(servoPin); // Attach the servo to the specified pin
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  int lightValue = analogRead(photoresistorPin); // Read the analog value from the photoresistor
  Serial.println(lightValue); // Print the light value for debugging
  
  if (lightValue < threshold) { // If the light value is below the threshold, move the servo to track the sun
    int angle = map(lightValue, 0, threshold, minAngle, maxAngle); // Map the light value to an angle for the servo
    solarServo.write(angle); // Move the servo to the calculated angle
  }
  delay(1000); // Wait for 1 second before checking again
}