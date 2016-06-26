#include "Servomotor.h"

Servomotor::Servomotor(int pin) : Actor(pin) {
	_servo.attach(pin);
	close();
}

void Servomotor::open() {
	_servo.write(END_POS);
}

void Servomotor::close() {
	_servo.write(START_POS);
}
