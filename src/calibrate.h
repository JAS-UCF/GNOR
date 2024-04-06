#ifndef EB528D13_C9D7_49AA_B375_87729973013A
#define EB528D13_C9D7_49AA_B375_87729973013A
#include <Arduino.h>
#include <Wire.h>
#include <QMC5883LCompass.h>
#include <TinyGPSPlus.h>
#ifdef CALIBRATE
void setup()
{
  QMC5883LCompass compass;
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
#endif // !CALIBRATE

#endif /* EB528D13_C9D7_49AA_B375_87729973013A */
