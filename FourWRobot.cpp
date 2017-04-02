/*
	FourWRobot.h - Library for controlling a robot with 4 wheels and an Arduino with a 
	motor shield

	Created by Nick Kotzalas, December 30, 2016
	Released into the public domain
*/

#include "Arduino.h"

#include <Wire.h>

bool debugEnabled = false;

/**
 * Constructor of the movement handler
 */
FourWRobot::FourWRobot(bool debug, int trigPin, int echoPin)
{
	debugEnabled = debug;
}

/**
 * Disengage the brakes and move to the requested direction (LOW: backwards, 
 * HIGH: forward), with the requested speed
 */
void _performMovement(int movementDirection, int movementSpeed, struct MotorSetup motor) {
  digitalWrite(motor.brakePin, LOW);
  digitalWrite(motor.directionPin, movementDirection);
  analogWrite(motor.speedPin, movementSpeed);
}

/**
 * Engage the brakes for the provided motor
 */
void _brakeMovement(struct MotorSetup motor) {
  digitalWrite(motor.brakePin, HIGH);
  analogWrite(motor.speedPin, 0);
}

/*
 * Setup the pins of the left motors and enable the appropriate pin modes
 */
void FourWRobot::setupLeftMotor(int directionPin, int speedPin, int brakePin, int currentPin)
{
	if (debugEnabled) {
		Serial.println("Initializing the left motors...");
	}

	_leftMotor.directionPin = directionPin;
	_leftMotor.speedPin = speedPin;
	_leftMotor.brakePin = brakePin;
	_leftMotor.currentPin = currentPin;

	// Initiate the motor of the left wheels (Channel A pin)
	pinMode(_leftMotor.directionPin, OUTPUT);
	// Initiate the brake of the left wheels (Channel A pin)
	pinMode(_leftMotor.brakePin, OUTPUT);

	if (debugEnabled) {
		Serial.println("Left motors initialized");
	}
}

/*
 * Setup the pins of the right motors and enable the appropriate pin modes
 */
void FourWRobot::setupRightMotor(int directionPin, int speedPin, int brakePin, int currentPin)
{
	if (debugEnabled) {
		Serial.println("Initializing the right motors...");
	}

	_rightMotor.directionPin = directionPin;
	_rightMotor.speedPin = speedPin;
	_rightMotor.brakePin = brakePin;
	_rightMotor.currentPin = currentPin;

	// Initiate the motor of the right wheels (Channel A pin)
	pinMode(_rightMotor.directionPin, OUTPUT);
	// Initiate the brake of the right wheels (Channel A pin)
	pinMode(_rightMotor.brakePin, OUTPUT);

	if (debugEnabled) {
		Serial.println("Right motors initialized");
	}
}

/*
 * Moves forward with the provided speed (speed is an integer between 0 and 
 * 255 that defines how fast the robot will move)
 */
void FourWRobot::moveForward(int speed)
{
	_performMovement(HIGH, speed, _rightMotor);
	_performMovement(LOW, speed, _leftMotor);
}

/*
 * Moves backwards with the provided speed (speed is an integer between 0 and 
 * 255 that defines how fast the robot will move)
 */
void FourWRobot::moveBackwards(int speed)
{
	_performMovement(LOW, speed, _rightMotor);
	_performMovement(HIGH, speed, _leftMotor);
}

/*
 * Turn right with the provided speed (speed is an integer between 0 and 255 
 * that defines how fast the robot will move)
 */
void FourWRobot::turnRight(int speed)
{
	_performMovement(HIGH, speed, _rightMotor);
	_performMovement(HIGH, speed, _leftMotor);
}

/*
 * Turn left with the provided speed (speed is an integer between 0 and 255 
 * that defines how fast the robot will move)
 */
void FourWRobot::turnLeft(int speed)
{
	_performMovement(LOW, speed, _rightMotor);
	_performMovement(LOW, speed, _leftMotor);
}

/*
 * Stop all movement
 */
void FourWRobot::brake()
{
	_brakeMovement(_rightMotor);
	_brakeMovement(_leftMotor);
}
