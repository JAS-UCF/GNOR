#include "deg-min-sec.hpp"
/**
 * @brief converts decimal coordinate to Degrees,minutes, seconds
 *
 * @param decimal coordinate to convert
 * @return degminsec_t
 */
degminsec_t decimal2degminsec(double decimal)
{
  int d = floor(decimal);
  int m = (decimal - d) * 60;
  double s = (m - floor(m)) * 60.0;
  degminsec_t t = {d, floor(m), s};
  return t;
}

double degminsec2decimal(degminsec_t degminsec)
{
  return degminsec.deg + (degminsec.min / 60) + (degminsec.sec / 3600);
}
