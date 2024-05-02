# Smart Car

## Introduction

This Smart Car project demonstrates the creation of an autonomous vehicle using Arduino. It aims to highlight the integration of servo motors for motion, an ultrasonic sensor for obstacle detection, and basic autonomous navigation functionalities.

## Components

- **Arduino Uno**: Acts as the brain of the Smart Car.
- **2x Servo Motors**: Facilitate forward and backward movements.
- **HC-SR04 Ultrasonic Sensor**: Enables obstacle detection.
- **Piezo Speaker**: Provides auditory signals or warnings.
- **Breadboard**: Used for mounting and connecting components.
- **Resistors and Jumper Wires**: Essential for safe and effective connections.


### Hardware Assembly

1. Attatch the Arduino to the chasise of the Parralax Arduino Shield
2. Connect the servo motors to the Arduino on pins 12 and 13.
3. Attach the ultrasonic sensor with the echo pin connected to pin 6 and the trigger pin to pin 5.
4. Place the piezo speaker on the breadboard and connect it to pin 8 on the Arduino.
5. Use resistors where necessary to protect the components.

### Software

The code for this project is available in the repository. It includes the following main functionalities:

- **Moving Forward and Backward**: Utilizes different speeds for servo motors.
- **Obstacle Detection**: Uses ultrasonic waves to detect obstacles and avoid collisions.
- **Audible Alerts**: Emits sounds through a piezo speaker when obstacles are detected.

### Pictures

I'm going to add the photos tomorrow

## Code Explanation

The Arduino sketch controls the car's movement based on input from the ultrasonic sensor. It includes functions for moving forward, moving backward, turning, stopping, and sounding the horn when an object is detected. Detailed comments in the code explain each function's purpose and usage.


## Conclusion

This project serves as my introduction to building autonomous vehicles with Arduino and could be expanded with more sensors and enhanced algorithms for improved functionality. 

