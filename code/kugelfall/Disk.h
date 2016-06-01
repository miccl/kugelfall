#pragma once

#include "Sensor.h"

class Disk {

private:
	const int ARC_LENGTH = 1;
	bool isWaiting;

 Sensor* _ps;

public:
	Disk(Sensor* ps);

	int getSpeed();
};
