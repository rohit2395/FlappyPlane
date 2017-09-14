#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"
#include "Engine\IO\Mouse.h"

#include <iostream>
using namespace std;

int main() {
  cout << "Hello Flappy Plane!" << endl;

  Engine engine;
  engine.Initialize("Flappy Plane!");
  
  //Sprite testSprite = Sprite("Assets/Art/DinoPlane.png",-100,-100);
  Sprite testSprite = Sprite("Assets/Art/Biplane.png", -100, -100);
  testSprite.SetScale(0.25f);
  
  while(true) {
    engine.Update();
    testSprite.Update();
    testSprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());
    if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
      testSprite.SetRotationBy(10);
    if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT))
      testSprite.SetRotationBy(-10);
    if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
      testSprite.SetRotationBy(0.1);
    engine.BeginRender();
    testSprite.Render();
    engine.EndRender();
  }
  return 0;
}
