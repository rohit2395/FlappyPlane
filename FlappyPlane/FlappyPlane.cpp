#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"
#include "Engine\IO\Mouse.h"
#include "Engine\IO\Keyboard.h"
#include "Game\Flapper.h"

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  cout << "Hello Flappy Plane!" << endl;

  //configuration
  static double SPEED = 0.1;
  static double ROTATION_SPEED = 10.0;
  static double SCALE = 0.1F;

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
  testSprite.SetScale(SCALE);
  testSprite.SpeedTo(SPEED);

  Flapper player(testSprite);

  while (true) {

    double now = glfwGetTime();
    delta += (now - lastTime) / ns;
    lastTime = now;

    //testSprite.MoveTo((double)Mouse::GetMouseX(), (double)Mouse::GetMouseY());
    /*if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
      player.GetSprite().RotateBy(ROTATION_SPEED);
    if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT))
      player.GetSprite().RotateBy(-ROTATION_SPEED);
    if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
      player.GetSprite().RotateBy(ROTATION_SPEED/10);

    if (Keyboard::Key(GLFW_KEY_W))
      player.GetRb().AddForce(Vector3(0,0.005,0));
    if (Keyboard::Key(GLFW_KEY_D))
      player.GetRb().AddForce(Vector3(0.005, 0,0));
    if (Keyboard::Key(GLFW_KEY_S))
      player.GetRb().AddForce(Vector3(0, -0.005, 0));
    if (Keyboard::Key(GLFW_KEY_A))
      player.GetRb().AddForce(Vector3(-0.05, 0, 0));*/

    if (delta >= 1.0) {
      //testSprite.MoveTo((double)Mouse::GetMouseX(), (double)Mouse::GetMouseY());
      if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
        player.GetSprite().RotateBy(ROTATION_SPEED);
      if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT))
        player.GetSprite().RotateBy(-ROTATION_SPEED);
      if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
        player.GetSprite().RotateBy(ROTATION_SPEED / 10);

      if (Keyboard::Key(GLFW_KEY_W))
        player.GetRb().AddForce(Vector3(0, SPEED, 0));
      if (Keyboard::Key(GLFW_KEY_D))
        player.GetRb().AddForce(Vector3(SPEED, 0, 0));
      if (Keyboard::Key(GLFW_KEY_S))
        player.GetRb().AddForce(Vector3(0,-SPEED, 0));
      if (Keyboard::Key(GLFW_KEY_A))
        player.GetRb().AddForce(Vector3(-SPEED, 0, 0));

      engine.Update();
      player.Update();
      updates++;
      delta--;
    }

    engine.BeginRender();
    player.Render();
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
