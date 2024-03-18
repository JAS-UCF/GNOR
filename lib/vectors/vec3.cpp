#include "vec3.hpp"
#include <cmath>

vec3 *vec3::Unit_Vec3()
{
  double n = this->Normal();
  return new vec3(this->x / n, this->y / n, this->z / n);
}
double vec3::Normal()
{
  return sqrt(pow(this->x, 2.0) + pow(this->y, 2.0) + pow(this->z, 2.0));
}