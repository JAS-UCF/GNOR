#ifndef EC5D9DD4_F6F1_427F_B521_037F4F2EEC2B
#define EC5D9DD4_F6F1_427F_B521_037F4F2EEC2B
#include <Arduino.h>
#include <datatypes.hpp>

/*
1 lat deg = 364000ft
1 lat min = 6068ft
1 lat sec = 101ft

2ft lat = 0.0198sec

1 lng deg = 288200ft
1 lng min = 4800ft
1 lng sec = 80ft
*/
#define Lat1Deg 364000;
#define Lat1Min 6068;
#define Lat1Sec 101;

#define Lng1Deg 288200;
#define Lng1Min 4800;
#define Lng1Sec 80;

#define Lat1FtMargin 0.00000961648452891
#define Lng1FtMargin 0.0000121408114113

typedef struct
{
  int deg;
  int min;
  double sec;
} degminsec_t;
degminsec_t decimal2degminsec(double decimal);
double degminsec2decimal(degminsec_t degminsec);
bool isLatLngA_x_fromLatLngB(latlng A, latlng B, double x);
double distanceLatLngA_x_fromLatLngB(latlng A, latlng B, double x);
double angleFromCoordinate(latlng coord1, latlng coord2);
#endif /* EC5D9DD4_F6F1_427F_B521_037F4F2EEC2B */
