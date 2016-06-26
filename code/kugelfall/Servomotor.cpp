#include "Servomotor.h"

//TODO: hier wäre die frage, ob wir es von Actor erben lassen, obwohl wir ja eigentlich das initialisieren mit dem pinMode brauchen bzw. ob es da zu irgendwelchen inteferenzen kommt.
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
