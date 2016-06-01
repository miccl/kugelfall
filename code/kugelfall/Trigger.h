#pragma once

#include "Sensor.h"

class Trigger : public Sensor {

protected:
	/**
	* Wether the trigger is activated or not.
	*/
	bool isActivated;
	/**
	* Number of activations.
	*/
	int count;


public:
	Trigger(int pin);
};
