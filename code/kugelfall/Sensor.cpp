#include "Sensor.h"

Sensor::Sensor(int pin) : _pin(pin){
	pinMode(pin, INPUT);
}

bool Sensor::getValue() {
	return digitalRead(_pin);
}

int Sensor::getPin() {
	return _pin;
}
