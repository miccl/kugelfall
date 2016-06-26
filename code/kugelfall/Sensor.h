#pragma once

#include "Component.h"

/**
 * A hardware sensor which is accessible by Arduino.
 */
class Sensor : public Component {

public:
  /**
   * Class constructor.
   */
	Sensor(int pin);

  /**
   * Returns the current value of the sensor.
   * 
   * @return current value.
   */
	bool getValue();
};
