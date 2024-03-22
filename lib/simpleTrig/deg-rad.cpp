#include "deg-rad.hpp"
#include <api/Common.h>

double rad2deg(double x)
{
  return x * RAD_TO_DEG;
}
double deg2rad(double x)
{
  return x * DEG_TO_RAD;
}