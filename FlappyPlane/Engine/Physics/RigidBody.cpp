#include "RigidBody.h"
#include "GLFW\glfw3.h"

#include <iostream>
using namespace std;
RigidBody::RigidBody() {
  friction = 1;
  gravity = 0;
}

void RigidBody::Initialize(Vector3* _pos, double* _rotation, Vector3* _scale, Vector3* _size, float _gravity, float _friction) {
  pos = _pos;
  rotation = _rotation;
  scale = _scale;
  size = _size;

  friction = _friction;
  gravity = _gravity;
}

void RigidBody::Update() {
  //handle friction effect
  if (velocity.x < 0.0)
    velocity.x += friction;
  else
    velocity.x -= friction;
  if (velocity.x <= 0.03 && velocity.x >= -0.03)
    velocity.x = 0.0;

  velocity.y -= gravity;
  *pos = *pos + velocity;

  //velocity = Vector3(0);
}

void RigidBody::Render(Vector3 color) {
  glLoadIdentity();
  glTranslatef(pos->x, pos->y, pos->z);
  glRotatef(*rotation, 0, 0, 1);
  glScalef(scale->x, scale->y, scale->z);

  glColor4f(color.x, color.y, color.z, 1);
  glBegin(GL_LINES);
  {
    glVertex2i((int)-size->x / 2, (int)-size->y / 2);
    glVertex2i((int)size->x / 2, (int)-size->y / 2);

    glVertex2i((int)size->x / 2, (int)-size->y / 2);
    glVertex2i((int)size->x / 2, (int)size->y / 2);

    glVertex2i((int)size->x / 2, (int)size->y / 2);
    glVertex2i((int)-size->x / 2, (int)size->y / 2);

    glVertex2i((int)-size->x / 2, (int)size->y / 2);
    glVertex2i((int)-size->x / 2, (int)-size->y / 2);
  }
  glEnd();
}

void RigidBody::AddForce(Vector3 force) {
  velocity = velocity + force;
}

void RigidBody::SetVel(Vector3 _vel) {
  velocity = _vel;
}