#include "Engine.h"

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL;


Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::initialize(char* windowTitle) {

  if (!glfwInit()) {
    cout << "Error initialzing glfw" << endl;
    return false;
  }
  window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
  if (window == NULL) {
    cout << "Error ocurred creating window!" << endl;
    return false;
  }

  //
  return true;

}