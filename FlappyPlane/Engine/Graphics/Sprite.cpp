#include "Sprite.h"
//#include <iostream>
//using namespace std;
Sprite::Sprite() {
  pos = Vector3(0);
  texture = Texture();
  rotation = 0;
  speed = 5;
}

Sprite::Sprite(string _imagePath) {
  pos = Vector3(0);
  texture = Texture(_imagePath);
  rotation = 0;
  speed = 5;
}

Sprite::Sprite(string _imagePath,Vector3 pos) {
  pos = Vector3(pos);
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
  glTranslatef(pos.x,pos.y, 0);
  glRotatef(rotation, 0, 0, 1);
  glScalef(scale.x,scale.y, 1);
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

void Sprite::SpeedTo(double _speed) {
  speed = _speed;
}

void Sprite::SpeedBy(double _speed) {
  speed += _speed;
}

void Sprite::MoveTo(Vector3 _pos) {
  pos = _pos;
}

void Sprite::MoveBy(Vector3 _pos) {
  pos = pos + _pos;
}

void Sprite::MoveLeft() {
  pos = pos - Vector3(speed, 0, 0);
}

void Sprite::MoveRight() {
  //cout << xPos << endl;
  pos = pos + Vector3(speed, 0, 0);
  //cout << speed<<endl;
}

void Sprite::MoveUp() {
  pos = pos + Vector3(0, speed, 0);
}

void Sprite::MoveDown() {
  pos = pos - Vector3(0, speed, 0);
}

void Sprite::RotateTo(double _rotation) {
  rotation = _rotation;
}

void Sprite::RotateBy(double _rotation) {
  rotation += _rotation;
}

void Sprite::SetScale(double _xyScale) {
  scale = Vector3(_xyScale);
}
void Sprite::SetScale(Vector3 scale) {
  scale = scale;
}