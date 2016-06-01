#include "Sensor.h"

Sensor::Sensor(int pin) : Component(pin) {
	pinMode(pin, INPUT);
}

bool Sensor::getValue() {
	return digitalRead(_pin);
}
