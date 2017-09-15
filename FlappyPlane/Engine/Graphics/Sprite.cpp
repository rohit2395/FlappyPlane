#include "Sprite.h"
//#include <iostream>
//using namespace std;
Sprite::Sprite() {
  xPos = 0;
  yPos = 0;
  texture = Texture();
  rotation = 0;
  speed = 5;
}

Sprite::Sprite(string _imagePath) {
  xPos = 0;
  yPos = 0;
  texture = Texture(_imagePath);
  rotation = 0;
  speed = 5;
}

Sprite::Sprite(string _imagePath, float _xPos, float _yPos) {
  xPos = _xPos;
  yPos = _yPos;
  texture = Texture(_imagePath);
  rotation = 0;
  speed = 5;
}

void Sprite::Update() {
}

void Sprite::Render() {
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture.GetId());
  glLoadIdentity();

  //translate -> rotate -> scale
  glTranslatef(xPos, yPos, 0);
  glRotatef(rotation, 0, 0, 1);
  glScalef(xScale, yScale, 1);
  //rendering
  glColor4f(1, 1, 1, 1);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);  glVertex2f(0, 0);
  glTexCoord2f(1, 0);  glVertex2f(texture.GetWidth(), 0);
  glTexCoord2f(1, 1);  glVertex2f(texture.GetWidth(), texture.GetHeight());
  glTexCoord2f(0, 1);  glVertex2f(0, texture.GetHeight());
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void Sprite::SpeedTo(float _speed) {
  speed = _speed;
}

void Sprite::SpeedBy(float _speed) {
  speed += _speed;
}

void Sprite::MoveTo(float _xPos, float _yPos) {
  xPos = _xPos;
  yPos = _yPos;
}

void Sprite::MoveLeft() {
  xPos -= speed;
}

void Sprite::MoveRight() {
  //cout << xPos << endl;
  xPos += speed;
  //cout << speed<<endl;
}

void Sprite::MoveUp() {
  yPos += speed;
}

void Sprite::MoveDown() {
  yPos -= speed;
}

void Sprite::RotateTo(float _rotation) {
  rotation = _rotation;
}

void Sprite::RotateBy(float _rotation) {
  rotation += _rotation;
}

void Sprite::SetScale(float _xyScale) {
  xScale = _xyScale;
  yScale = _xyScale;
}
void Sprite::SetScale(float _xScale, float _yScale) {
  xScale = _xScale;
  yScale = _yScale;
}