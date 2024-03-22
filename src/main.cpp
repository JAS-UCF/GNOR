#include <Arduino.h>
#include <Wire.h>
#include <QMC5883LCompass.h>
#include <datatypes.hpp>
#include <deg-min-sec.hpp>
#include "config.h"
#include "calibrate.h"
#include <PID_RT.h>

#define MOTOR_LEFT 27
#define MOTOR_RIGHT 26

QMC5883LCompass compass;
PID_RT PID;

#ifdef RUN

static const latlng waypoints[4] = {
    {28.599610, -81.201771},
    {28.599756, -81.201840},
    {28.599730, -81.202067},
    {28.599586, -81.202147}};
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

  // initalizing the COMPASS
  compass.init();

  delay(100); // wait 100ms

  // init PID
  PID.setOutputRange(0, 360);
  PID.setInterval(50);
  PID.setK(PID_GAIN, PID_INTEGRAL, PID_DERIVATIVE);
  PID.start();
}

void loop()
{
  // if we are done
  if (waypointSelect = sizeof(waypoints) / sizeof(latlng))
  {
    return;
  }
  // put your main code here, to run repeatedly:

  // TODO, implement the GPS device, read in the serial data and interpret where we are and where we need to be

  // tells the compass to read in our values
  compass.read();

  // this is where we can read in the GPS position we are in
  // assuming we have some latlng of our current position
  latlng pos = {0, 0};

  // now lets see if we are within 2 feet of our gps position
  if (isLatLngA_x_fromLatLngB(pos, waypoints[waypointSelect], 2))
  {
    // set our next waypoint
    waypointSelect++;
  }

  // since we need to keep moving, we need to find our bearing in comparison to the true north, then find the angle between that and the next waypoint.
  // using the angle from where we are facing to where we need to be facing, we can begin correcting for this using a correction factor
  // these factors will be multiplied in, when taking into account the propultion of the 2 motors, using this, we can steer and move forward
  // any steering correction cannot exceede 1, and may not fall below STEERING_CORRECTION_MIN
  double steeringCorrectionLEFT = 0.0;
  double steeringCorrectionRIGHT = 0.0;
  double directionFacing = 360 - (compass.getAzimuth() - 90); // get the direction in degrees we are facing
  // we need to subtract by 90 b/c azimuth uses 360 / 0 as up, where for any trig function to work, we need to rotate our perspective 90°

  double angle_between_us_waypoint = angleFromCoordinate(pos, waypoints[waypointSelect]);

  PID.setPoint(angle_between_us_waypoint);
  PID.setOutputRange(0, 360);
  PID.compute(directionFacing);

  // steering bias should help us to determine how much of each engine should be running, this will be calibrated once we get our hands one the motors & compass modules
  double steering_bias = PID.getOutput();
}
#endif // !RUN
