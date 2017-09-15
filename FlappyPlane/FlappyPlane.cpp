#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"
#include "Engine\IO\Mouse.h"
#include "Engine\IO\Keyboard.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  cout << "Hello Flappy Plane!" << endl;

  Engine engine;
  engine.Initialize("Flappy Plane!");

  double lastTime = glfwGetTime();
  double delta = 0.0;
  double ns = 1.0 / 60.0;
  double timer = lastTime;
  int frames = 0;
  int updates = 0;

  Sprite testSprite = Sprite("Assets/Art/DinoPlane.png");
  //Sprite testSprite = Sprite("Assets/Art/Biplane.png");
  testSprite.SetScale(0.25f);
  testSprite.SpeedTo(0.1);
  while (true) {

    double now = glfwGetTime();
    delta += (now - lastTime) / ns;
    lastTime = now;

    //testSprite.MoveTo((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());
    if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
      testSprite.RotateBy(10);
    if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT))
      testSprite.RotateBy(-10);
    if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
      testSprite.RotateBy(0.1);

    if (Keyboard::Key(GLFW_KEY_W))
      testSprite.MoveUp();
    if (Keyboard::Key(GLFW_KEY_D))
      testSprite.MoveRight();
    if (Keyboard::Key(GLFW_KEY_S))
      testSprite.MoveDown();
    if (Keyboard::Key(GLFW_KEY_A))
      testSprite.MoveLeft();

    if (delta >= 1.0) {
      engine.Update();
      testSprite.Update();
      updates++;
      delta--;
    }

    engine.BeginRender();
    testSprite.Render();
    engine.EndRender();
    frames++;

    if (glfwGetTime() - timer > 1.0) {
      timer++;
      string fps = to_string(frames);
      string ups = to_string(updates);
      string title = "Flappy Plane UPS:" + ups + "||FPS:" + fps;
      engine.SetWindowTitle(title.c_str());
      updates = 0;
      frames = 0;
    }
  }
  return 0;
}
