#include "deg-rad.hpp"
#include <api/Common.h>

double rad2deg(double x)
{
  return x / (PI / 180);
}
double deg2rad(double x)
{
  return x * (PI / 180);
}