#include <iostream>
#include "Engine/Engine.h"

using namespace std;
int main() {
  cout << "Hello Flappy Plane!" << endl;
  Engine engine;
  engine.Initialize("Flappy Plane!");
  while(true) {
    engine.Update();
    engine.Render();
  }
  return 0;
}
