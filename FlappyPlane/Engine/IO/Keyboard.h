#ifndef FLAPPY_KEYBOARD
#define FLAPPY_KEYBOARD

#include "GLFW\glfw3.h"

class Keyboard
{
public:

  static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mod);

  static bool Key(int key);
  static bool KeyDown(int key);
  static bool KeyUp(int key);
private:
  static bool keys[];
  static bool keysDown[];
  static bool keysUp[];
};

#endif FLAPPY_KEYBOARD
