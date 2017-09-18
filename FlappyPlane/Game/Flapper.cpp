#include "Flapper.h"

Flapper::Flapper() {
}

Flapper::Flapper(Sprite _sprite) {
  sprite = _sprite;
  rb.Initialize(sprite.GetPos(),sprite.GetRotation(),sprite.GetScale(),sprite.GetSize(),0.00,0.03);
}

void Flapper::Update() {
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