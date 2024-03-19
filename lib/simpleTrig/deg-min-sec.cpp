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
/**
 * @brief Checks to see if LatLngA +- x in each direction contains LatLngB
 *
 * @param A LatLng of our position
 * @param B LatLng of the position to check against
 * @param x Radius in ft to check around LatLngA
 * @return true if LatLngA is within x feet of LatLngB
 * @return false if LatLngA is not within x feet of LatLngB
 */
bool isLatLngA_x_fromLatLngB(latlng A, latlng B, double x)
{
  // turns each coord into lat lng interface
  degminsec_t LatA = decimal2degminsec(A.lat);
  degminsec_t LngA = decimal2degminsec(A.lng);
  degminsec_t LatB = decimal2degminsec(B.lat);
  degminsec_t LngB = decimal2degminsec(B.lng);
  LatA.sec + x / Lat1Sec;
  LngA.sec + x / Lng1Sec;

  // check the latitudes first
  if (abs(
          (degminsec2decimal(LatA) / degminsec2decimal(LatB)) * 100) -
          100 <=
      x / Lat1FtMargin)
  {
    // check to see if the longitudes are valid
    if (abs(
            (degminsec2decimal(LngA) / degminsec2decimal(LngB)) * 100) -
            100 <=
        x / Lng1FtMargin)
    {

      return true;
    }
  }
  return false;
}
/**
 * @brief finds the closest possible distance remaining between LatLngA +- x to contain LatLngB
 *
 * @param A LatLng of our position
 * @param B LatLng of the position to check against
 * @param x Radius in ft to check around LatLngA
 * @returns double the distance remaining between the closest point on LatlngA +-x to contain LatLngB
 */
double distanceLatLngA_x_fromLatLngB(latlng A, latlng B, double x)
{
  return -1.0;
}