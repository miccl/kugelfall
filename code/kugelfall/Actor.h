#pragma once

#include "Arduino.h"

class Actor {

protected:
	int _pin;

public:
	Actor(int pin);

	void setValue(int value);
};
