/* Example sketch that uses the FourWRobot library */
#include <FourWRobot.h>

// Debug logs are enabled and test mode is active (switch to false to disable)
const bool debug = false;

// Create the instance of the FourWRobot
FourWRobot robot = FourWRobot(debug); 

/* Pin wiring map */
// Left motor pins
const int LEFT_DIRECTION = 13;
const int LEFT_SPEED = 11;
const int LEFT_BRAKE = 8;
const int LEFT_CURRENT = 1;

// Right motor pins
const int RIGHT_DIRECTION = 12;
const int RIGHT_SPEED = 3;
const int RIGHT_BRAKE = 9;
const int RIGHT_CURRENT = 0;

void setup() {
  Serial.begin(9600);

  // Initialize the motors
  robot.setupLeftMotor(LEFT_DIRECTION, LEFT_SPEED, LEFT_BRAKE, LEFT_CURRENT);
  robot.setupRightMotor(RIGHT_DIRECTION, RIGHT_SPEED, RIGHT_BRAKE, RIGHT_CURRENT);
}

void loop() {
  if (Serial.available() > 0) {
      // read the incoming byte:
      int incomingByte = Serial.read();
      if (incomingByte == 'N') {
        Serial.println("Forward");
        robotCar.moveForward(100);
      } else if (incomingByte == 'S') {
        Serial.println("Reverse");
        robotCar.moveBackwards(100);
      } else if (incomingByte == 'E') {
        Serial.println("Left");
        robotCar.turnLeft(100);
      } else if (incomingByte == 'W') {
        Serial.println("Right");
        robotCar.turnRight(100);
      } else if (incomingByte == 'B') {
        Serial.println("Brake");
        robotCar.brake();
      }
  }  
}
