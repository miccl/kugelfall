#include "Sensor.h"

Sensor::Sensor(int pin) {
	pinMode(pin, INPUT);
}

bool Sensor::getValue() {
	return digitalRead(pin);
}

int Sensor::getPin() {
	return pin;
}
