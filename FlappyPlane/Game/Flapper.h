#ifndef FLAPP_FLAPPER
#define FLAPP_FLAPPER

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/RigidBody.h"

class Flapper
{
public:
  
  Flapper();
  Flapper(Sprite _sprite, double _scale);
  Flapper(char* _spritePath,double _scale);

  void Update();
  void Render();

  void Flap();

  Sprite& GetSprite();
  RigidBody& GetRb();
private:
  Sprite sprite;
  RigidBody rb;
};

#endif FLAPP_FLAPPER
