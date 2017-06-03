/*
	FourWRobot.h - Library for controlling a robot with 4 wheels and an Arduino with a 
	motor shield

	Created by Nick Kotzalas, December 30, 2016
	Released into the public domain
*/

#ifndef FourWRobot_h
#define FourWRobot_h

#include "Arduino.h"

/**
 * Structure that represents the pins of a motor shield 
 * that correspond to a dc motor
 */
typedef struct MotorSetup {
  int directionPin;
  int speedPin;
  int brakePin;
  int currentPin;
};

class FourWRobot
{
	public:
		FourWRobot(bool debug);

		/*
		 * Setup the pins of the left motors and enable the appropriate pin modes
		 */
		void setupLeftMotor(int directionPin, int speedPin, int brakePin, int currentPin);

		/*
		 * Setup the pins of the right motors and enable the appropriate pin modes
		 */
		void setupRightMotor(int directionPin, int speedPin, int brakePin, int currentPin);

		/*
		 * Moves forward with the provided speed (speed is an integer between 0 and 
		 * 255 that defines how fast the robot will move)
		 */
		void moveForward(int speed);

		/*
		 * Moves backwards with the provided speed (speed is an integer between 0 and 
		 * 255 that defines how fast the robot will move)
		 */
		void moveBackwards(int speed);

		/*
		 * Turn right with the provided speed (speed is an integer between 0 and 255 
		 * that defines how fast the robot will move)
		 */
		void turnRight(int speed);

		/*
		 * Turn left with the provided speed (speed is an integer between 0 and 255 
		 * that defines how fast the robot will move)
		 */
		void turnLeft(int speed);

		/*
		 * Stop all movement
		 */
		void brake();

	private:
		struct MotorSetup _rightMotor;
		struct MotorSetup _leftMotor;
};

#endif