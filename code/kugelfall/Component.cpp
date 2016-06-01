#include "Sensor.h"

Component::Component(int pin) : _pin(pin){
	pinMode(pin, INPUT);
}

int Component::getPin() {
	return _pin;
}
