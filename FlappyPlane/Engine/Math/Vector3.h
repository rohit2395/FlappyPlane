#ifndef FLAPPY_VECTOR3
#define FLAPPY_VECTOR3

class Vector3
{
public:

  Vector3();
  Vector3(const Vector3& other);
  Vector3(double _x);
  Vector3(double _x, double _y, double _z);

  Vector3& operator=(const Vector3& other);
  Vector3 operator+(const Vector3& other);
  Vector3 operator-(const Vector3& other);
  Vector3 operator*(const Vector3& other);
  Vector3 operator*(double _x);

  bool operator==(const Vector3& other);
  bool operator!=(const Vector3& other);

  double x;
  double y;
  double z;
private:

};

#endif FLAPPY_VECTOR3
