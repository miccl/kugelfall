#include "Actor.h"

Actor::Actor() {
	pinMode(pin, OUTPUT);
}

void Actor::setValue(int value) {
	digitalWrite(pin, value);
}
