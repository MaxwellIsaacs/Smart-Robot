#include <Servo.h> // Include the Servo library

/* Global variables and pin definitions */
const int servoRightPin = 12; // Pin for right servo
const int servoLeftPin = 13;  // Pin for left servo
const int piezoPin = 8;       // Piezo speaker on digital pin 8
const int echoPin = 6;        // Echo pin for the ultrasonic sensor
const int trigPin = 5;        // Trigger pin for the ultrasonic sensor

Servo servoRight; // Servo object for the right wheel
Servo servoLeft;  // Servo object for the left wheel

/*
 * @brief Setup function to initialize pin modes and serial communication
 */
void setup() {
  servoRight.attach(servoRightPin);
  servoLeft.attach(servoLeftPin);
  
  Serial.begin(9600); // Initialize serial communication at 9600 bps
  
  pinMode(trigPin, OUTPUT); // Set the trig pin as output
  pinMode(echoPin, INPUT);  // Set the echo pin as input
}

/*
 * @brief Main loop function to handle car movements and obstacle detection
 */
void loop() {
  moveBackward(); // Keep moving backward as the standard movement

  long distance = measureDistance(); // Measure distance to obstacle
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 20) {
    honkHonk(); // Sound the horn if obstacle is too close
    backUpAndTurn(); // Back up and then perform a larger turn

    // Optionally, continue moving backward or change to a different movement after turning
  }
  
  delay(200); // Short delay to allow loop restart
}

/*
 * @brief Moves the car forward
 */
void moveForward() {
  servoRight.writeMicroseconds(1700); // Speed for right servo
  servoLeft.writeMicroseconds(1300);  // Speed for left servo
}

/*
 * @brief Sounds the horn twice
 */
void honkHonk() {
  int frequency = 1000; // Frequency in Hz for horn sound
  int duration = 100;   // Duration in ms for each honk
  int pause = 150;      // Pause in ms between honks
  
  tone(piezoPin, frequency, duration);
  delay(duration + pause);
  
  tone(piezoPin, frequency, duration);
  delay(duration + pause);
}

/*
 * @brief Turns the car right
 */
void turnRight() {
  servoRight.writeMicroseconds(1300); // Same speed for both servos to turn right
  servoLeft.writeMicroseconds(1300);
  delay(200); // Adjust this delay to complete the turn
}

/*
 * @brief Measures distance to obstacle using ultrasonic sensor
 * @return long - Distance to obstacle in cm
 */
long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // Calculate distance
  return distance;
}

/*
 * @brief Moves the car backward
 */
void moveBackward() {
  servoRight.writeMicroseconds(1300); // Speed for right servo to move backward
  servoLeft.writeMicroseconds(1700);  // Speed for left servo to move backward
}

/*
 * @brief Stops the car's movement
 */
void stopMovement() {
  servoRight.writeMicroseconds(1500); // Neutral speed stops the servo
  servoLeft.writeMicroseconds(1500);
}

/*
 * @brief Performs a complete turn to avoid obstacles
 */
void completeTurn() {
  turnRight(); // Perform a turn to the right
  delay(1500); // Increased delay to ensure a larger turn
  
  stopMovement(); // Stop for a brief moment after turning
  delay(100); // Short pause
}

/*
 * @brief Backs up and then performs a complete turn
 */
void backUpAndTurn() {
  moveBackward(); // Move backward to create more space
  delay(1000); // Increased delay for a larger step back
  stopMovement(); // Stop before turning
  completeTurn(); // Now perform the larger turn
}
