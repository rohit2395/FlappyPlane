#ifndef FLAPPY_TEXTURE
#define FLAPPY_TEXTURE

#include "GLFW\glfw3.h"
#include "SOIL\src\SOIL.h"
#include <iostream>
#include <string>

using namespace std;
class Texture {
public:
  Texture();
  Texture(int _id);
  Texture(string _path);

  int GetId();
  int GetWidth();
  int GetHeight();

private:
  bool GetTextureParams();
  int id;
  int width, height;

};
#endif FLAPPY_TEXTURE
