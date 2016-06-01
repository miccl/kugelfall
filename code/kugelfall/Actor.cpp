#include "Actor.h"

Actor::Actor(int pin) : _pin(pin) {
	pinMode(pin, OUTPUT);
}

void Actor::setValue(int value) {
	digitalWrite(_pin, value);
}
