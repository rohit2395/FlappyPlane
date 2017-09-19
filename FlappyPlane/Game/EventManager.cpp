#include "EventManager.h"



EventManager::EventManager(Flapper* _player) {
  player = _player;
}

void EventManager::Update() {

  if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
    player->Flap();
  }

  /*if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
    player->GetSprite().RotateBy(ROTATION_SPEED);
  if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT))
    player->GetSprite().RotateBy(-ROTATION_SPEED);
  if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
    player->GetSprite().RotateBy(ROTATION_SPEED / 10);

  if (Keyboard::Key(GLFW_KEY_W))
    player->GetRb().AddForce(Vector3(0, SPEED, 0));
  if (Keyboard::Key(GLFW_KEY_D))
    player->GetRb().AddForce(Vector3(SPEED, 0, 0));
  if (Keyboard::Key(GLFW_KEY_S))
    player->GetRb().AddForce(Vector3(0, -SPEED, 0));
  if (Keyboard::Key(GLFW_KEY_A))
    player->GetRb().AddForce(Vector3(-SPEED, 0, 0));*/
}