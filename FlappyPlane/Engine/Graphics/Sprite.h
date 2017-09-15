#ifndef FLAPPY_SPRITE
#define FLAPPY_SPRITE

#include <iostream>
#include <string>

#include "Texture.h"
#include "../Math/Vector3.h"

using namespace std;

class Sprite {
public:
  Sprite();
  Sprite(string _imagePath);
  Sprite(string _imagePath, Vector3 pos);
  
  void Update();
  void Render();
  
  void SpeedTo(double _speed);
  void SpeedBy(double _speed);

  void MoveTo(Vector3 pos);
  void MoveBy(Vector3 pos);
  void MoveLeft();
  void MoveRight();
  void MoveUp();
  void MoveDown();

  void RotateTo(double _rotation);
  void RotateBy(double _rotation);

  void SetScale(double _xyScale);
  void SetScale(Vector3 scale);
private:
  Texture texture;
  Vector3 pos;
  double rotation;
  Vector3 scale;
  double speed;
};

#endif FLAPPY_SPRITE
