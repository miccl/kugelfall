#pragma once
#include "Arduino.h"

class Sensor {

private:
	int pin;

public:
	Sensor(int pin);

	int getValue();
};
