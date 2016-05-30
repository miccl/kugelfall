#pragma once

#include <Servo.h>
#include "Actor.h"

class Servomotor : public Actor {

private:
	const int endPos = 20;

	const int startPos = 0;

protected:
	const int servoPin = 9;

	Servo servo;

public:
	Servomotor();

	/**
	* Opens the release.
	*/
	void open();

	/**
	* Closes the release.
	*/
	void close();
};
