#pragma once

#include "Component.h"


class Sensor : public Component {

public:
	Sensor(int pin);

  /**
   * Returns the current value of the sensor.
   * 
   * @return TODO
   */
	bool getValue();
};
