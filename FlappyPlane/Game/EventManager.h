#ifndef FLAPPY_EVENTMANAGER
#define FLAPPY_EVENTMANAGER

#include "Flapper.h"
#include "..\Engine\IO\Keyboard.h"
#include "..\Engine\IO\Mouse.h"

class EventManager
{
public:
  EventManager(Flapper* _player);
  void Update();

private:
  Flapper* player;
};

#endif // !FLAPPY_EVENTMANAGER
