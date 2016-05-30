#include "Servomotor.h"

Servomotor::Servomotor() {
	servo.attach(servoPin);
	close();
}

void Servomotor::open() {
	servo.write(endPos);
}

void Servomotor::close() {
	servo.write(startPos);
}
