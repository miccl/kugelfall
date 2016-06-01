#pragma once

#include <Servo.h>
#include "Actor.h"

class Servomotor : public Actor {

private:
	const int endPos = 20;

	const int startPos = 0;

protected:
	Servo _servo;

public:
	Servomotor(int pin);

	/**
	* Opens the release.
	*/
	void open();

	/**
	* Closes the release.
	*/
	void close();
};
