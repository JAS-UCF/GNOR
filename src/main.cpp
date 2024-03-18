#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include "datatypes.hpp"
#define MOTOR_LEFT 27
#define MOTOR_RIGHT 26

void setup()
{
  // set pins to output
  pinMode(MOTOR_LEFT, OUTPUT);  // init left
  pinMode(MOTOR_RIGHT, OUTPUT); // init right

  // Adjust PWM properties if needed
  /*
  analogWriteFreq(5000);
  analogWriteRange(65535);
  analogWriteResolution(16);
  */
}

void loop()
{
  // put your main code here, to run repeatedly:

  // TODO, implement the GPS device, read in the serial data and interpret where we are and where we need to be
  // TODO, use the IMU to find our current orientation, without this, we have no idea how we are facing, and cannot be accurate about the execution of our action
}