#ifndef FLAPPY_SPRITE
#define FLAPPY_SPRITE

#include <iostream>
#include <string>

#include "Texture.h"

using namespace std;

class Sprite {
public:
  Sprite();
  Sprite(string _imagePath);
  Sprite(string _imagePath, float _xPos, float _yPos);
  
  void Update();
  void Render();
  
  void SpeedTo(float _speed);
  void SpeedBy(float _speed);

  void MoveTo(float _xPos, float _yPos);
  void MoveBy(float _xPos, float _yPos);
  void MoveLeft();
  void MoveRight();
  void MoveUp();
  void MoveDown();

  void RotateTo(float _rotation);
  void RotateBy(float _rotation);

  void SetScale(float _xyScale);
  void SetScale(float _xScale,float _yScale);
private:
  Texture texture;
  float xPos;
  float yPos;
  float rotation;
  float xScale;
  float yScale;
  float speed;
};

#endif FLAPPY_SPRITE
