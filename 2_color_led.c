/*
    Project name : 2-color LED module
    Modified Date: 13-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-2-color-led-module
*/

const int redLEDPin = 9;    // Pin connected to the red LED
const int greenLEDPin = 10; // Pin connected to the green LED
const int delayTime = 1000; // Delay time in milliseconds

void setup() {
  pinMode(redLEDPin, OUTPUT);    // Set the red LED pin as OUTPUT
  pinMode(greenLEDPin, OUTPUT);  // Set the green LED pin as OUTPUT
  Serial.begin(9600);            // Initialize serial communication
}

void loop() {
  switchColors(); // Call the function to switch colors
  delay(delayTime); // Wait for a second before switching again
}

// Function to switch between red and green colors
void switchColors() {
  static bool isRedOn = true; // Static variable to keep track of the current color state

  if (isRedOn) {
    turnOnRedLED();
    Serial.println("Red LED is ON");
  } else {
    turnOnGreenLED();
    Serial.println("Green LED is ON");
  }

  isRedOn = !isRedOn; // Toggle the color state
}

// Function to turn on the red LED and turn off the green LED
void turnOnRedLED() {
  digitalWrite(redLEDPin, HIGH);   // Turn on red LED
  digitalWrite(greenLEDPin, LOW);  // Turn off green LED
}

// Function to turn on the green LED and turn off the red LED
void turnOnGreenLED() {
  digitalWrite(redLEDPin, LOW);    // Turn off red LED
  digitalWrite(greenLEDPin, HIGH); // Turn on green LED
}
