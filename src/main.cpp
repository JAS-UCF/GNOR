#include <Arduino.h>
#include <Wire.h>
#include <QMC5883LCompass.h>
#include <datatypes.hpp>
#include <deg-min-sec.hpp>
#include "config.h"
#include "calibrate.h"
#include <TinyGPSPlus.h>

#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"
#include "pico/multicore.h"

#define MOTOR_LEFT 27
#define MOTOR_RIGHT 26

QMC5883LCompass compass;

#ifdef RUN

static const latlng waypoints[4] = {
    {28.599610, -81.201771},
    {28.599756, -81.201840},
    {28.599730, -81.202067},
    {28.599586, -81.202147}};
int waypointSelect = 0;
void setup()
{
  waypointSelect = 0; // reset the waypoint select to target the starting waypoint

  Serial.begin(9600);
  // set pins to output
  pinMode(MOTOR_LEFT, OUTPUT);  // init left
  pinMode(MOTOR_RIGHT, OUTPUT); // init right

  pwm_set_gpio_level(MOTOR_LEFT, 0);
  pwm_set_gpio_level(MOTOR_RIGHT, 0);

  delay(100); // wait 100ms
}

void setup1()
{
  compass.init();
}

void loop1()
{
  // TODO
  /*
    Integrate the compass code in here, read in the compass information and pass it to a global compass object
    Integrate the GPS module in here, and pass it to a global GPS object
  */
  compass.read();
}

void loop()
{
  // if we are done
  if (waypointSelect = (sizeof(waypoints) / sizeof(latlng)))
  {
    return;
  }

  // TODO
  /*
  Read in the global GPS object and make computations from there
  Read in the global COMPASS object and make computations from there
  */

  // put your main code here, to run repeatedly:

  // tells the compass to read in our values
  compass.read();

  // TODO, implement the GPS device, read in the serial data and interpret where we are and where we need to be
  // this is where we can read in the GPS position we are in
  // assuming we have some latlng of our current position
  // currently we are setting to {0,0}
  // this needs to be set to our true position
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
  double directionFacing = 360 - (compass.getAzimuth() - 90); // get the direction in degrees we are facing
  // we need to subtract by 90 b/c azimuth uses 360 / 0 as up, where for any trig function to work, we need to rotate our perspective 90°

  double angle_between_us_waypoint = angleFromCoordinate(pos, waypoints[waypointSelect]);

  double angle_delta = angle_between_us_waypoint - directionFacing;

  double steering_bias = map(angle_delta, -180, 180, STEERING_CORRECTION_MIN, 1.0);

  // if the angle delta is positive we turn to the left
  // if the angle detla is negative we turn to the right

  if (angle_delta > 0)
  {
    // turn to the left
    pwm_set_gpio_level(MOTOR_LEFT, (0xFF * abs((uint8_t)steering_bias)) << 8);
    pwm_set_gpio_level(MOTOR_RIGHT, 0xFF << 8);
  }
  else if (angle_delta < 0)
  {
    // turn to the right
    pwm_set_gpio_level(MOTOR_RIGHT, (0xFF * abs((uint8_t)steering_bias)) << 8);
    pwm_set_gpio_level(MOTOR_LEFT, 0xFF << 8);
  }
  else
  {
    // if somehow we get 0 (just for error safety)
    pwm_set_gpio_level(MOTOR_LEFT, 0xFF << 8);
    pwm_set_gpio_level(MOTOR_RIGHT, 0xFF << 8);
  }
}
#endif // !RUN
