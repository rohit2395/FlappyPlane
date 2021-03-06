#include "Engine.h"
#include "IO\Mouse.h"
#include "IO\Keyboard.h"
int Engine::SCREEN_WIDTH = 1366 * 2 / 5;
int Engine::SCREEN_HEIGHT = 768 * 2 / 5;
GLFWwindow* Engine::window = NULL;

Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::SetWindowTitle(const char* windowTitle) {
  glfwSetWindowTitle(window, windowTitle);
}

bool Engine::Initialize(char* windowTitle) {

  if (!glfwInit()) {
    cout << "Error initialzing glfw" << endl;
    return false;
  }
  window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
  if (window == NULL) {
    cout << "Error ocurred creating window!" << endl;
    return false;
  }

  //OpenGL setup
  glfwMakeContextCurrent(window);
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glfwSwapInterval(1);

  glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
  glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
  glfwSetKeyCallback(window, Keyboard::KeyCallback);

  const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
  //cout << mode->height << endl;
  //cout << mode->width << endl;
  //cout << SCREEN_HEIGHT << endl;
  //cout << SCREEN_WIDTH << endl;
  int xPos = (mode->width - SCREEN_WIDTH) / 2;
  int yPos = (mode->height - SCREEN_HEIGHT) / 2;
  //cout << xPos << endl << yPos << endl;
  glfwSetWindowPos(window, xPos, yPos);


  //GL setup
  //view port
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, width, 0, height, -10, 10);
  glDepthRange(-10, 10);
  glMatrixMode(GL_MODELVIEW);

  //alpha blending
  glEnable(GL_ALPHA_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  return true;
}

void Engine::Update() {
  glfwPollEvents(); 
}

void Engine::BeginRender() {
  glClearColor(0, 1, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::EndRender() {
  glfwSwapBuffers(window);
}