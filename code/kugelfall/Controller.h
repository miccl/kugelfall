#pragma once

#include "Arduino.h"
#include "Sensor.h"
#include "Servomotor.h"
#include "Trigger.h"

class Controller {
private:
	Sensor* hallSensor;
	Sensor* photoSensor;
	Servomotor* servomotor;
	Trigger* trigger;
protected:
	const int FALL_DURATION = 0;

public:
	Controller(Sensor* ps, Sensor* hs, Servomotor* sm, Trigger* tg);

	int getReleaseTime();

	int getHoleDelay();

	void rele(int releaseTime);

	void photo();

	void hall();

	void trigg();
};
