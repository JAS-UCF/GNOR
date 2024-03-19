#include <Arduino.h>
#include <Wire.h>
#include <QMC5883LCompass.h>
#include <datatypes.hpp>
#include <deg-min-sec.hpp>
#include "config.h"

#define MOTOR_LEFT 27
#define MOTOR_RIGHT 26

QMC5883LCompass compass;

latlng waypoints[4] = {
    {28.599610f, -81.201771f},
    {28.599756f, -81.201840f},
    {28.599730f, -81.202067f},
    {28.599586f, -81.202147f}};
int waypointSelect = 0;

#ifdef RUN
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
}
#endif // !RUN

#ifdef CALIBRATE

void setup()
{
  Serial.begin(9600);
  compass.init();

  Serial.println("This will provide calibration settings for your QMC5883L chip. When prompted, move the magnetometer in all directions until the calibration is complete.");
  Serial.println("Calibration will begin in 5 seconds.");
  delay(5000);

  Serial.println("CALIBRATING. Keep moving your sensor...");
  compass.calibrate();

  Serial.println("DONE. Copy the lines below and paste it into your projects sketch.);");
  Serial.println();
  Serial.print("compass.setCalibrationOffsets(");
  Serial.print(compass.getCalibrationOffset(0));
  Serial.print(", ");
  Serial.print(compass.getCalibrationOffset(1));
  Serial.print(", ");
  Serial.print(compass.getCalibrationOffset(2));
  Serial.println(");");
  Serial.print("compass.setCalibrationScales(");
  Serial.print(compass.getCalibrationScale(0));
  Serial.print(", ");
  Serial.print(compass.getCalibrationScale(1));
  Serial.print(", ");
  Serial.print(compass.getCalibrationScale(2));
  Serial.println(");");
}

void loop()
{
  delay(1000);
}
#endif // DEBUG