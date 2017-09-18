#ifndef FLAPPY_RIGIDBODY
#define FLAPPY_RIGIDBODY

#include "../Math/Vector3.h"
class RigidBody
{
public:

  RigidBody();
  void Initialize(Vector3* _pos, double* _rotation, Vector3* _scale,Vector3* _size, float _gravity, float _friction);

  void Update();
  void Render(Vector3 color);

  void AddForce(Vector3 force);

private:
  Vector3* pos;
  double* rotation;
  Vector3* scale;
  Vector3* size;

  double gravity;
  double friction;
  Vector3 velocity;
};
#endif FLAPPY_RIGIDBODY
