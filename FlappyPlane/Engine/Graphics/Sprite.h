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
  void SetPos(float _xPos, float _yPos);
  void SetRotationTo(float _rotation);
  void SetRotationBy(float _rotation);
  void SetScale(float _xyScale);
  void SetScale(float _xScale,float _yScale);
private:
  Texture texture;
  float xPos;
  float yPos;
  float rotation;
  float xScale;
  float yScale;
};

#endif FLAPPY_SPRITE
