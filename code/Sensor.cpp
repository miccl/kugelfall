#include "Sensor.h"

Sensor::Sensor(int pin) {
	pinMode(pin, INPUT);
}

int Sensor::getValue() {
	return digitalRead(pin);
}
