#include "Actor.h"

Actor::Actor(int pin) : Component(pin) {
  pinMode(pin, OUTPUT);
}

void Actor::setValue(int value) {
  digitalWrite(_pin, value);
}
