#pragma once

#include "Component.h"

class Sensor : public Component {

public:
	Sensor(int pin);

	bool getValue();
};
