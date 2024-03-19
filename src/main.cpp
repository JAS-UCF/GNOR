#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "datatypes.hpp"

#define MOTOR_LEFT 27
#define MOTOR_RIGHT 26

Adafruit_MPU6050 mpu;
/*
1 lat deg = 164000ft
1 lat min = 6068ft
1 lat sec = 101ft

2ft lat = 0.0198sec
*/

latlng waypoints[4] = {
    {28.599610f, -81.201771f},
    {28.599756f, -81.201840f},
    {28.599730f, -81.202067f},
    {28.599586f, -81.202147f}};
int waypointSelect = 0;

void setup()
{
  int waypointSelect = 0; // reset the waypoint select to target the starting waypoint

  Serial.begin(9600);
  // set pins to output
  pinMode(MOTOR_LEFT, OUTPUT);  // init left
  pinMode(MOTOR_RIGHT, OUTPUT); // init right

  // Adjust PWM properties if needed
  /*
  analogWriteFreq(5000);
  analogWriteRange(65535);
  analogWriteResolution(16);
  */

  // initalizing the IMU
  if (!mpu.begin())
  {
    Serial.println("Failed to find MPU6050 chip");
    while (1)
    {
      delay(10);
    }
  }
  // attempt to set IMU ranges
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100); // wait 100ms
}

void loop()
{
  // put your main code here, to run repeatedly:

  // TODO, implement the GPS device, read in the serial data and interpret where we are and where we need to be

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // this is where we can read in the GPS position we are in
  // assuming we have some latlng of our current position
  latlng pos = {0, 0};

  // now lets see if we are within 2 feet of our gps position
}