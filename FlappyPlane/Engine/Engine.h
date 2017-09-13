#ifndef FLAPPY_ENGINE
#define FLAPPY_ENGINE

#include "GLFW\glfw3.h"
#pragma comment(lib,"opengl32.lib")

#include <iostream>
using namespace std;

class Engine
{
public:
  static int SCREEN_HEIGHT;
  static int SCREEN_WIDTH;

  Engine();
  ~Engine();

  bool initialize(char* windowTitle);
private:
  static GLFWwindow* window;
};

#endif


