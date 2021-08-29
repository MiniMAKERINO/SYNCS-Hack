// Code Libraries
#include <Servo.h> 

// Variable Setup
int servoPosition;
int maxAngle = 45;


// Assigning pins
const int servoPin = 7;
const int laserPin = 11;
const int buzzer = 5;


// Create servo object
Servo Servo1;


void setup() {
  Serial.begin(9600);

  Servo1.attach(servoPin); // Attach the servo to the allocated pin
  pinMode(laserPin, OUTPUT); // Set laser pin mode to OUTPUT
  pinMode(buzzer, OUTPUT); // Set buzzer pin mode to OUTPUT
  
  
}

void loop() {

  // Set random servo position and wait 3 seconds
  servoPosition = random(0, maxAngle);
  Servo1.write(servoPosition);
  delay(3000);


  // Turn on laser for 1 second
  digitalWrite(laserPin, HIGH);
  tone(buzzer, 1000); // Make the buzzer beep at 1000kHz
  delay(100);
  noTone(buzzer);
  delay(900);

  // Turn off laser
  digitalWrite(laserPin, LOW);
  tone(buzzer, 500); // Make the buzzer beep at 500kHz
  delay(100);
  noTone(buzzer);
}
