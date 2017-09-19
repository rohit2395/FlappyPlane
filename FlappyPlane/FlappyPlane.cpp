#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"
#include "Game\Flapper.h"
#include "Game\EventManager.h"

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


  Flapper player = Flapper("Assets/Art/DinoPlane.png",0.1F);
  EventManager eventmgr = EventManager(&player);
  while (true) {

    double now = glfwGetTime();
    delta += (now - lastTime) / ns;
    lastTime = now;


    if (delta >= 1.0) {
      engine.Update();
      eventmgr.Update();
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
