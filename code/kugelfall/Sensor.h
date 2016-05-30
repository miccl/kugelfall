#pragma once

#include "Arduino.h"

class Sensor {

protected:
	int pin;

public:
	Sensor(int pin);

	bool getValue();

	int getPin();
};
