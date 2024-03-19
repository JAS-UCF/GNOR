#ifndef AFD95024_FB6D_470F_BBBB_A49A546CE744
#define AFD95024_FB6D_470F_BBBB_A49A546CE744
#include <vec3.hpp>
class Vec3_Rect : public vec3
{
public:
  Vec3_Rect(double x, double y, double) : vec3(x, y, z){};
  Vec3_Rect(Vec3_Rect &&) = default;
  Vec3_Rect(const Vec3_Rect &) = default;
  Vec3_Rect &operator=(Vec3_Rect &&) = default;
  Vec3_Rect &operator=(const Vec3_Rect &) = default;
  ~Vec3_Rect();

private:
};

Vec3_Rect::Vec3_Rect(double x, double y, double) : vec3(x, y, z)
{
}

Vec3_Rect::~Vec3_Rect()
{
}

#endif /* AFD95024_FB6D_470F_BBBB_A49A546CE744 */
