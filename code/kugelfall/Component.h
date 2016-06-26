#pragma once

#include "Arduino.h"

/**
 * A hardware component which is accesible by Arduino.
 */
class Component {

protected:
  /**
   * The number of the pin connected to the component.
   */
  int _pin;

public:
  /**
   * Class constructor.
   * 
   * @param pin The number of the pin connected to the component.
   */
  Component(int pin);

  /**
   * Returns the instance pin.
   */
  int getPin();
};
