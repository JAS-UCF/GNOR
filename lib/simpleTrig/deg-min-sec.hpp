#ifndef EC5D9DD4_F6F1_427F_B521_037F4F2EEC2B
#define EC5D9DD4_F6F1_427F_B521_037F4F2EEC2B
#include <Arduino.h>

typedef struct
{
  int deg;
  int min;
  double sec;
} degminsec_t;
degminsec_t decimal2degminsec(double decimal);
#endif /* EC5D9DD4_F6F1_427F_B521_037F4F2EEC2B */
