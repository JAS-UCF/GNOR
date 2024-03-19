#ifndef CCC2C106_6AB2_4C7E_BE6D_62636388470D
#define CCC2C106_6AB2_4C7E_BE6D_62636388470D
class vec3
{
public:
  double x, y, z;
  vec3(double x, double y, double z)
  {
    this->x = x;
    this->y = y;
    this->z = z;
  }
  vec3(vec3 &&) = default;
  vec3(const vec3 &) = default;
  vec3 &operator=(vec3 &&) = default;
  vec3 &operator=(const vec3 &) = default;
  ~vec3() {}
  double Normal();
  double Dot_product(vec3 *vectorA, vec3 *vectorB);
  double Dot_product(vec3 *vectorB);
  double Angle_Between(vec3 *vectorB);
  double Angle_Between(vec3 *vectorA, vec3 *vectorB);
  vec3 *Unit_Vec3();

private:
};

#endif /* CCC2C106_6AB2_4C7E_BE6D_62636388470D */
