#pragma once

#include "Arduino.h"

class Actor {

protected:
	int pin;
	int value;
public:
	Actor();

	void setValue(int value);
};
