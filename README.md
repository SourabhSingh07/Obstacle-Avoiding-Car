# Obstacle-Avoiding Car with ESP32

## Overview
This repository contains the source code and documentation for an Obstacle-Avoiding Car, a self-driving vehicle that can autonomously navigate while avoiding obstacles. The car uses an ESP32 microcontroller, L298N motor driver, servo motor, and four wheels for movement. When it detects an obstacle in its path, it intelligently steers away from it, ensuring a safe and autonomous navigation experience.

## Features
- **Obstacle Avoidance**: The car utilizes ultrasonic sensors to detect obstacles in its path and takes evasive action to avoid collisions.
- **Scalability**: The project's modular design allows for easy upgrades and modifications.

## Hardware Components
- **ESP32 Microcontroller**: The brain of the car, responsible for processing sensor data and controlling the motors.
- **L298N Motor Driver**: Drives the four motors for the car's movement.
- **Servo Motor**: Used for controlling the car's steering mechanism.
- **Ultrasonic Sensors**: Detect obstacles in front of the car.
- **Chassis and Wheels**: The physical structure and wheels that make up the car.

## Getting Started
1. **Setting up the Hardware**: Assemble the car chassis, and attach the motors, servo motor, and ultrasonic sensors according to the provided instructions.

2. **Software Installation**: Flash the ESP32 microcontroller with the provided code in the 'src' directory. Make sure to install any necessary libraries and dependencies.

3. **Power On**: Power up the car.

## Code Structure
- `src/`: Contains the Arduino code for the ESP32 microcontroller.
- `docs/`: Documentation and datasheets for the hardware components.
- `schematics/`: Circuit diagrams and schematics for the project.

## Acknowledgments
- Special thanks to the open-source community for their contributions and inspiration.

Happy Coding!
