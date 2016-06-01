#pragma once

#include "Arduino.h"

class Sensor {

protected:
	int _pin;

public:
	Sensor(int pin);

	bool getValue();

	int getPin();
};
