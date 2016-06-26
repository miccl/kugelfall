#pragma once

#include "Component.h"

/**
 * An hardware actor which is accessible by Arduino.
 */
class Actor : public Component {

public:
  /**
   * Class constructor.
   * Initialises the actor with the given pin.
   * 
   * @param pin The number of the pin connected to the actor.
   */
  Actor(int pin);

  /**
   * Sets the actor to the given value.
   * 
   * @param The value to which the actor should be set.
   */
  void setValue(int value);
};
