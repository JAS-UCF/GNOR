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
/**
 * @brief dot product between 2 vectors
 * returns the magnitude, of which if we pointed 90 degrees toward the VecA, we would need to change our magnitude to align the vectors
 * @param vectorA first vector VecA
 * @param vectorB second vector VecB
 * @return double
 */
double vec3::Dot_product(vec3 *vectorA, vec3 *vectorB)
{
  return (vectorA->x * vectorB->x) + (vectorA->y * vectorB->y) + (vectorA->z * vectorB->z);
}
/**
 * @brief dot product between the source vector3 and the provided vector3
 * returns the magnitude, of which if we pointed 90 degrees toward the source vec3, we would need to change our magnitude to align the vectors
 * @param vectorB second vector VecB
 * @return double
 */
double vec3::Dot_product(vec3 *vectorB)
{
  return (this->x * vectorB->x) + (this->y * vectorB->y) + (this->z * vectorB->z);
}
/**
 * @brief finds the angle between this vector and VectorB,
 *
 * @param vectorB the vector to find the angle between
 * @return double angle in RADIANS
 */
double vec3::Angle_Between(vec3 *vectorB)
{
  return acos(
      this->Dot_product(vectorB) / (abs(this->Normal()) * abs(this->Normal())));
}
/**
 * @brief find the angle between vectorA and vectorB
 *
 * @param vectorA
 * @param vectorB
 * @return double angle in RADIANS
 */
double vec3::Angle_Between(vec3 *vectorA, vec3 *vectorB)
{
  return acos(
      vectorA->Dot_product(vectorB) /
      (abs(vectorA->Normal()) * abs(vectorA->Normal())));
}
