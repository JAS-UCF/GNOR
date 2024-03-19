#ifndef B65AEEAF_70F8_484E_8503_C1E922B7EB3C
#define B65AEEAF_70F8_484E_8503_C1E922B7EB3C
#include <Arduino.h>
#include <vec3.hpp>
typedef struct
{
  vec3 acceleration;
  vec3 rotation;
} imu_data;

typedef struct
{
  double lat;
  double lng;
} latlng;

#endif /* B65AEEAF_70F8_484E_8503_C1E922B7EB3C */
