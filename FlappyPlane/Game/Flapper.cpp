#include "Flapper.h"

Flapper::Flapper() {
}

Flapper::Flapper(Sprite _sprite, double _scale) {
  sprite = _sprite;
  sprite.SetScale(_scale);
  rb.Initialize(sprite.GetPos(),sprite.GetRotation(),sprite.GetScale(),sprite.GetSize(),0.03,0.03);
}

Flapper::Flapper(char* _spritepath, double _scale) {
  sprite = Sprite(_spritepath,Vector3(200,100,0));
  sprite.SetScale(_scale);
  rb.Initialize(sprite.GetPos(), sprite.GetRotation(), sprite.GetScale(), sprite.GetSize(), 0.2, 0.03);
}

void Flapper::Flap() {
  rb.SetVel(Vector3(0,7, 0));
  sprite.RotateTo(10);
}

void Flapper::Update() {
  sprite.RotateBy(-0.5);
  sprite.Update();
  rb.Update();
}

void Flapper::Render() {
  sprite.Render();
  rb.Render(Vector3(0, 0, 0));
}

Sprite& Flapper::GetSprite() {
  return sprite;
}

RigidBody& Flapper::GetRb() {
  return rb;
}