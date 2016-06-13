#include "Sensor.h"

Sensor::Sensor(int pin) : Component(pin) {
	pinMode(pin, INPUT_PULLUP);
}

bool Sensor::getValue() {
	return digitalRead(_pin);
}
